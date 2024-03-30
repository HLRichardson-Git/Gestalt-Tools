cmake_minimum_required(VERSION 3.16.3)
project(GestaltTools)

include(FetchContent)
FetchContent_Declare(
    Gestalt
    URL https://github.com/HLRichardson-Git/Gestalt/archive/refs/tags/gestalt-0.3.1.zip
)
FetchContent_MakeAvailable(Gestalt)

# Add your Gestalt Tools source files here
add_executable(GestaltTools main.cpp)

# Link Gestalt library to GestaltTools
target_link_libraries(GestaltTools PRIVATE Gestalt)
