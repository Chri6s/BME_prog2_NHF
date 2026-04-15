add_library(memtrace STATIC memtrace.cpp memtrace.h)

target_include_directories(memtrace PUBLIC .)

target_compile_features(memtrace PRIVATE cxx_std_98)

target_compile_definitions(memtrace PUBLIC MEMTRACE)
