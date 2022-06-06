#ifndef SENSORS_W1_SENSOR_H
#define SENSORS_W1_SENSOR_H

#include <string>

/** Onewire sensor implementation */
class W1Sensor
{
public:
    /** Constructor
     *
     * @param temperature_filename Temperature filename as from /sys (can be any file though)
     */
    W1Sensor(const std::string& temperature_filename)
    : _temperature_filename(temperature_filename) {}

    /** Get the temperature
     *
     * Reads the temperature from its file (and performs sanity checks
     * on the way)
     */
    double get_temperature();

private:
    std::string _temperature_filename;
};

#endif
