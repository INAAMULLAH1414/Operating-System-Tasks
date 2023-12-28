cmake_minimum_required(VERSION 3.10)

project(OperatingSystemTasks VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the source files
set(SOURCES
    header.h
    task1.h
    task2.h
    task3client.h
    task3client.h
    main.c
)

# Create the executable
add_executable(OperatingSystemTasks ${SOURCES})
