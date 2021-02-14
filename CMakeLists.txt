cmake_minimum_required(VERSION 3.10)
find_package(SFML REQUIRED COMPONENTS graphics)
# set the project name
project(hangman)

# add the executable
add_executable(hangman main.cpp)
