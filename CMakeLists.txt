cmake_minimum_required(VERSION 3.10)
project(MySFMLProject)

# Set the C++ standard to C++17 or higher
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set path to SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.0/lib/cmake/SFML")

# Find SFML package with all components for SFML 3.0.0
find_package(SFML 3 COMPONENTS System Window Graphics Audio Network REQUIRED)

# List all your source files
set(SOURCE_FILES
    src/main.cpp
    src/player.cpp
    src/GameCore.cpp
    src/fieldLines.cpp
    src/Ball.cpp
    src/AiBot.cpp
    src/ScoreBoard.cpp
    src/Menu.cpp
)

# Add the executable with all source files
add_executable(MySFMLProject ${SOURCE_FILES})

# Add compiler warning flags
if(MSVC)
    # MSVC compiler flags
    target_compile_options(MySFMLProject PRIVATE /W4)
else()
    # GCC/Clang compiler flags
    target_compile_options(MySFMLProject PRIVATE -Wall -Wextra -pedantic)
endif()

# Link all SFML libraries
target_link_libraries(MySFMLProject PRIVATE 
    SFML::System
    SFML::Window
    SFML::Graphics
    SFML::Audio
    SFML::Network
)

# Include directories should be handled automatically, but just in case:
target_include_directories(MySFMLProject PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/SFML-3.0.0/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/headers"  # Add this to easily include your own headers
)

# Add a custom command to run the executable after building
add_custom_command(TARGET MySFMLProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running ${PROJECT_NAME}..."
    COMMAND $<TARGET_FILE:MySFMLProject>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Executing program..."
)