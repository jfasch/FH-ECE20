#include <unistd.h>
#include <iostream>

#include <w1-sensor.h>


int main(int argc, char** argv)
{
    if (! (argc == 3 || argc == 4)) {
        fprintf(stderr, "%s <filename> <interval>\n", argv[0]);
        return 42;
    }
    
    const char* filename = argv[1];
    const char* interval_str = argv[2];
    int niterations = -1;

    if (argc == 4)
        niterations = atoi(argv[3]);

    int interval = atoi(interval_str);
    unsigned int time_remaining;

    W1Sensor sensor{filename};

    int iteration = 0;
    while (niterations == -1 || iteration++ < niterations) {
        double temperature = sensor.get_temperature();

        std::cout << temperature << std::endl;
        
        time_remaining = sleep(interval);
        if (time_remaining != 0)
            fprintf(stderr, "did not sleep %d seconds, %d remaining\n", interval, time_remaining);
    }

    return 0;
}
