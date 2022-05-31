 add_library(
   c++-school STATIC 

   some-function.h
   some-function.cpp 
)
target_include_directories(c++-school PUBLIC .)
