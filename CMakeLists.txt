# Configuración del compilador
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

# Configuración del proyecto
set(THIS TurboCodes)
project(${THIS})

# Activación de googletest
enable_testing()
add_subdirectory(googletest)

# Ficheros de la librería
set(HEADERS lib/common.h lib/TurboBit.h)
set(SOURCES src/common.cpp src/TurboBit.cpp)

# Configuración de la librería
add_library(${THIS} ${HEADERS} ${SOURCES})
add_executable(${THIS}_EXEC main.cpp ${HEADERS} ${SOURCES})
target_include_directories(${THIS} PUBLIC lib)
target_include_directories(${THIS} PUBLIC src)

# Tests de la librería
add_subdirectory(tests)
