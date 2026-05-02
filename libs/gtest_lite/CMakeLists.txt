add_library(gtest_lite gtest_lite.h)
target_include_directories(gtest_lite PUBLIC .)

target_link_libraries(gtest_lite PUBLIC memtrace)
