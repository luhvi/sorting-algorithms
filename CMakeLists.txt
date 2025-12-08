cmake_minimum_required(VERSION 3.16)
project(sfml_game)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/sfml/3.0.2")

find_package(SFML 3.0 COMPONENTS Window Graphics Audio Network REQUIRED)

add_executable(sfml_game main.cpp)

target_link_libraries(sfml_game
    SFML::Window
    SFML::Graphics
    SFML::Audio
    SFML::Network
)
