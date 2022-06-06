#include "fixtures.h"

#include <w1-sensor.h>

#include <gtest/gtest.h>
#include <sstream>


class w1_sensor_suite : public TestWithTemporaryFile
{
public:
    void write_temperature(double temperature)
    {
        int temperature_int = temperature * 1000;

        std::string temperature_string = std::to_string(temperature_int);
        temperature_string += '\n';

        write_temperature_raw(temperature_string);
    }

    void write_temperature_raw(const std::string& s)
    {
        ssize_t nwritten = ::write(this->tmpfd(), s.c_str(), s.size());
        ASSERT_EQ(nwritten, s.size());

        // rewind file pointer back to beginning
        off_t pos = ::lseek(this->tmpfd(), 0, SEEK_SET);
        ASSERT_NE(pos, -1);
    }
};

TEST_F(w1_sensor_suite, all_fine)
{
    this->write_temperature(36.5);

    W1Sensor sensor{this->tmpfilename()};
    double temperature = sensor.get_temperature();

    ASSERT_FLOAT_EQ(temperature, 36.5);
}

TEST_F(w1_sensor_suite, nonexisting_temperature_file)
{
    ASSERT_THROW(W1Sensor{this->tmpfilename()+"-noexist"}.get_temperature(), std::exception);
}

TEST_F(w1_sensor_suite, malformed_temperature_file)
{
    this->write_temperature_raw("bullshit");

    W1Sensor sensor{this->tmpfilename()};
    ASSERT_THROW(sensor.get_temperature(), std::exception);
}
