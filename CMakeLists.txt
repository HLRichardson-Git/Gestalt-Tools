cmake_minimum_required(VERSION 3.16.3)

set(Project_Name GestaltTools)
project(${Project_Name} VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Fetch Gestalt
include(FetchContent)
FetchContent_Declare(
    Gestalt
    #URL https://github.com/HLRichardson-Git/Gestalt/archive/refs/tags/gestalt-0.3.1.zip
    URL https://github.com/HLRichardson-Git/Gestalt/archive/refs/heads/9-implement-the-ecdsa-pkc-algorithms.zip
)

# Fetch Google Benchmark
FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/refs/tags/v1.8.3.zip
)

# Set Google Benchmark options
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)

# Make Google Test and Google Benchmark available
FetchContent_MakeAvailable(Gestalt)
FetchContent_MakeAvailable(googlebenchmark)

add_subdirectory(benches)