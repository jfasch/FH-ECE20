#include <gtest/gtest.h>
#include <constant-sensor.h>


TEST(sensor_suite, constant_sensor)
{
    ConstantSensor sensor{36.5};
    double temperature = sensor.get_temperature();

    ASSERT_FLOAT_EQ(temperature, 36.5);
}

TEST(sensor_suite, w1_sensor)
{
    W1Sensor sensor{"/sys/bus/w1/devices/28-deadbeef/temperature"};
    double temperature = sensor.get_temperature();

    ASSERT_FLOAT_EQ(temperature, 36.5);
}
