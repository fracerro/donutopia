cmake_minimum_required(VERSION 3.16)
project(Donutopia VERSION 0.1.0)

# abilita il supporto per i test, tra cui l'opzione BUILD_TESTING usata sotto
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# richiedi l'uso di C++17, senza estensioni non-standard offerte dal compilatore usato 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# abilita warning
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")

# abilita l'address sanitizer e l'undefined-behaviour sanitizer in debug mode
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

add_executable(donutopia source/main.cpp source/matrix.cpp source/point.cpp source/camera.cpp source/solid.cpp source/render.cpp source/rgb.cpp)

# se il testing e' abilitato...
#   per disabilitare il testing, passare -DBUILD_TESTING=OFF a cmake durante la fase di configurazione
if (BUILD_TESTING)

  # aggiungi l'eseguibile matrix.test.t
  add_executable(matrix.test.t  source/test/matrix.test.cpp source/matrix.cpp source/point.cpp)
  # # aggiungi l'eseguibile matrix.test.t alla lista dei test
  add_test(NAME matrix.test.t COMMAND matrix.test.t)

  add_executable(point.test.t  source/test/point.test.cpp source/matrix.cpp source/point.cpp)
  add_test(NAME point.test.t COMMAND point.test.t)

endif()

