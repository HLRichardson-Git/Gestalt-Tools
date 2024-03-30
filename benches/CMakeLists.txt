cmake_minimum_required(VERSION 3.16.3)

set (This benches)

set (Sources
    aesBenchs.cpp
    sha1Benches.cpp
    # Add more benchmark files as needed
)

add_executable (${This} ${Sources})

target_link_libraries (${This} PRIVATE Gestalt benchmark::benchmark)