add_library(string string5.cpp string5.h)
target_include_directories(string PUBLIC .)

target_link_libraries(string PUBLIC memtrace)
