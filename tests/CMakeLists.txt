
# Configuración del compilador
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

# Configuración del proyecto
set(THIS TurboCodesTest)
project(${THIS})

# Ficheros de la librería
set(SOURCE TurboBitset_Test.cpp Rsc_Test.cpp)

# Configuración de los tests
add_executable(${THIS} ${SOURCE})
target_include_directories(${THIS} PUBLIC ../lib)
target_include_directories(${THIS} PUBLIC ../src)

target_link_libraries(${THIS} gtest_main TurboCodes)

add_test(NAME ${THIS} COMMAND ${THIS})