#ifndef SENSORS_CONSTANT_SENSOR_H
#define SENSORS_CONSTANT_SENSOR_H

class ConstantSensor
{
public:
    ConstantSensor(double temperature)
    {
        _temperature = temperature;
    }

    double get_temperature()
    {
        return _temperature;
    }

private:
    double _temperature;
};

#endif
