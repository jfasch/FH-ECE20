ADD_EXECUTABLE(
  run-tests

  gtest-demo-suite.cpp
)
TARGET_LINK_LIBRARIES(run-tests gtest_main)
