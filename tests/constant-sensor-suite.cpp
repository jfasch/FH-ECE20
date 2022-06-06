#include <gtest/gtest.h>
#include <constant-sensor.h>


TEST(constant_sensor_suite, basic)
{
    ConstantSensor sensor{36.5};
    double temperature = sensor.get_temperature();

    ASSERT_FLOAT_EQ(temperature, 36.5);
}
