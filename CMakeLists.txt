cmake_minimum_required(VERSION 3.16)
project(Donutopia VERSION 1.0)

# enable test support
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# require C++ 17 without compiler extensions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# enable warnings
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")

# enable in debug mode the address sanitizer and undefined-behaviour
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

# compile the library
add_library(donutopia STATIC source/matrix.cpp source/point.cpp source/rgb.cpp source/camera.cpp source/shape.cpp source/solid.cpp source/render.cpp)

# build tests only if BUILD_TESTING is True
if (BUILD_TESTING)

  # aggiungi l'eseguibile matrix.test.t
  add_executable(matrix.test.t  source/test/matrix.test.cpp source/matrix.cpp source/point.cpp)
  # # aggiungi l'eseguibile matrix.test.t alla lista dei test
  add_test(NAME matrix.test.t COMMAND matrix.test.t)

  add_executable(point.test.t  source/test/point.test.cpp source/matrix.cpp source/point.cpp)
  add_test(NAME point.test.t COMMAND point.test.t)

  add_executable(render.test.t source/test/render.test.cpp source/matrix.cpp source/point.cpp source/camera.cpp source/render.cpp source/rgb.cpp source/shape.cpp)
  add_test(NAME render.test.t COMMAND render.test.t)

endif()
