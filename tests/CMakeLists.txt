ADD_EXECUTABLE(
  run-tests

  gtest-demo-suite.cpp
  c++-string-suite.cpp
  constant-sensor-suite.cpp
  w1-sensor-suite.cpp
)

target_link_libraries(
  run-tests

  PUBLIC

  gtest_main
  c++-school
  sensors
)
