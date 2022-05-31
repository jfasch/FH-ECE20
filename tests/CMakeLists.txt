ADD_EXECUTABLE(
  run-tests

  basic.cpp
)
TARGET_LINK_LIBRARIES(run-tests gtest_main)
