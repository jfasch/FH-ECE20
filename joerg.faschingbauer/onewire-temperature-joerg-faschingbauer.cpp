// #include <w1-sensor.h>
#include <constant-sensor.h>

#include <unistd.h>
#include <iostream>


static void loop_and_measure_and_print(unsigned int interval, int niterations, ConstantSensor& sensor)
{
    unsigned int time_remaining;
    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        double temperature = sensor.get_temperature();
        std::cout << temperature << std::endl;

        time_remaining = sleep(interval);
        if (time_remaining != 0)
            std::cerr << "did not sleep " << interval << " seconds, " << time_remaining << " remaining" << std::endl;
    }
}

int main(int argc, char** argv)
{
    if (! (argc == 3 || argc == 4)) {
        fprintf(stderr, "%s <filename> <interval>\n", argv[0]);
        return 42;
    }
    
    const char* filename = argv[1];
    (void)filename;  // suppress "unused" warning
    const char* interval_str = argv[2];
    int niterations = -1;

    if (argc == 4)
        niterations = atoi(argv[3]);

    int interval = atoi(interval_str);

    //W1Sensor sensor{filename};
    ConstantSensor sensor{38.5};
    loop_and_measure_and_print(interval, niterations, sensor);

    return 0;
}
