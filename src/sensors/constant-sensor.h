#ifndef SENSORS_CONSTANT_SENSOR_H
#define SENSORS_CONSTANT_SENSOR_H

/** Constant sensor (for testing purposes) */
class ConstantSensor
{
public:
    /** Constructor
     * @param temperature The temperature to return at get_temperature()
     */
    ConstantSensor(double temperature)
    {
        _temperature = temperature;
    }

    double get_temperature();

private:
    double _temperature;
};

#endif
