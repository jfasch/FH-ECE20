 add_library(
   sensors STATIC 

   constant-sensor.h
   constant-sensor.cpp
)
target_include_directories(sensors PUBLIC .)
