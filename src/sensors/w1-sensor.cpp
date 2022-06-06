#include "w1-sensor.h"

#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>






#include <iostream>


using namespace std;

namespace {
class ScopedFD
{
public:
    ScopedFD(int fd): _fd(fd) {}
    ~ScopedFD()
    {
        if (_fd >= 0)
            ::close(_fd);
    }

    operator int() const { return _fd; }
    
private:
    int _fd;
};
}

double W1Sensor::get_temperature()
{
    ScopedFD fd = ::open(_temperature_filename.c_str(), O_RDONLY);

    if (fd == -1) {
        int error = errno;
        std::ostringstream msg;
        msg << "Cannot open " << _temperature_filename << " (" << error << ')';
        throw std::runtime_error(msg.str());
    }

    // we expect the temperature file to not be longer than a few
    // bytes (e.g. "36000\n", in millidegrees celsius):

    // * all data is read in one read operation
    // * another read sees EOF
    std::string temperature_string;

    char buffer[32];
    ssize_t nread = ::read(fd, buffer, sizeof(buffer));
    if (nread == -1) {
        int error = errno;
        std::ostringstream msg;
        msg << "Cannot read " << _temperature_filename << " (" << error << ')';
        throw std::runtime_error(msg.str());
    }

    if (nread == 0) {
        std::ostringstream msg;
        msg << "Reading " << _temperature_filename << ": premature end of file";
        throw std::runtime_error(msg.str());
    }

    temperature_string.assign(buffer, nread);

    // insist in EOF
    nread = ::read(fd, buffer, sizeof(buffer));
    if (nread != 0) {
        std::ostringstream msg;
        msg << "Reading " << _temperature_filename << ": not seeing EOF at second read";
        throw std::runtime_error(msg.str());
    }

    std::size_t pos;
    double temperature = std::stod(temperature_string, &pos);

    // nitpickingly, assert that the temperature is immediately
    // followed by linefeed
    if (temperature_string[pos] != '\n') {
        std::ostringstream msg;
        msg << "Reading " << _temperature_filename << ": malformed temperature data: not a linefeed (\\n) seen at position " << pos;;
        throw std::runtime_error(msg.str());
    }

    return temperature/1000;
}
