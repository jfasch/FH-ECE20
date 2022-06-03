ADD_EXECUTABLE(
  run-tests

  gtest-demo-suite.cpp
  c++-string-suite.cpp
  sensor-suite.cpp
)

target_link_libraries(
  run-tests

  PUBLIC

  gtest_main
  c++-school
  sensors
)
