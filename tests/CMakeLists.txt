ADD_EXECUTABLE(
  run-tests

  gtest-demo-suite.cpp
  c++-school-suite.cpp
)

target_link_libraries(
  run-tests

  PUBLIC

  gtest_main
  c++-school
)
