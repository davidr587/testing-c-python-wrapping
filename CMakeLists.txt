# Versión mínima de CMake y nombre del proyecto
cmake_minimum_required(VERSION 3.14)
project(Laboratory2)

# --- Descargar y configurar Google Test ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# !! ESTA LÍNEA ES LA SOLUCIÓN AL ERROR LNK2038 !!
# Fuerza a GTest a usar la misma librería runtime que nuestro proyecto (MDd/MD)
set(gtest_force_shared_crt ON CACHE BOOL "")

FetchContent_MakeAvailable(googletest)

# --- Configurar nuestro proyecto ---
enable_testing()

# Define la carpeta 'include' para que los #include funcionen
include_directories(include)

# Crea una librería con nuestro código fuente
add_library(my_functions src/Functions.cpp)

# Crea el programa ejecutable de los tests
add_executable(runTests tests/main_test.cpp)

# Enlaza la librería de nuestro código y GTest con el programa de tests
target_link_libraries(runTests PRIVATE my_functions gtest_main)

# Descubre automáticamente todos los tests definidos con TEST()
include(GoogleTest)
gtest_discover_tests(runTests)