 add_library(
   c++-school STATIC 

   point.h
   point.cpp

   copy-good.h
)
target_include_directories(c++-school PUBLIC .)
