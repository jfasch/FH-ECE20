 add_library(
   sensors STATIC 

   constant-sensor.h
   constant-sensor.cpp

   w1-sensor.h
   w1-sensor.cpp
)
target_include_directories(sensors PUBLIC .)
