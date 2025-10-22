# Tests Unitarios con GTest y Pytest

Este repositorio contiene la implementación y los tests unitarios para un conjunto de funciones de manipulación de bits en C++ y Python.

## Proceso Realizado 

El proyecto se ha reestructurado para seguir las prácticas actualizadas de desarrollo de C++ con CMake:
- **`src/` y `include/`**: El código fuente se ha separado en archivos de implementación (`.cpp`) y de cabecera (`.h`) para mejorar la modularidad. De esta forma se pueden modificar archivos sin afectar los demas o reautilizar los archivos.
- **`CMakeLists.txt`**: Se ha modernizado para usar el método `FetchContent`. Esto permite que CMake descargue y configure automáticamente la librería Google Test, eliminando la necesidad de instalarla manualmente en el sistema.
- **`tests/`**: Contiene todos los archivos de test para el código C++.

- ## 1. Tests con Gtest (C++)

Los tests unitarios en C++ (en la carpeta `tests/`) verifican el comportamiento de la aritmética de 32 bits sin signo, prestando especial atención al **"wrapping" o desbordamiento**.

### Funcionalidad Testeada
* **`wrapFunctionAdd`**: Se comprueba tanto una suma normal como una suma que causa un desbordamiento (`UINT_MAX + 1 = 0`).
* **`wrapFunctionMul`**: Se testea una multiplicación simple y una que resulta en desbordamiento (`UINT_MAX * UINT_MAX = 1`).
* **`wrapFunctionShift`**: Se verifica el comportamiento de la rotación circular de bits hacia la izquierda (circular shift).

### Pasos para Ejecutar los Tests de C++
Es necesario tener `cmake` y un compilador de C++ (como Visual Studio/GCC/Clang) instalados.

1.  **Crear y entrar al directorio de compilación:**
    ```bash
    mkdir build
    cd build
    ```
2.  **Configurar el proyecto (CMake descargará GTest):**
    ```bash
    cmake ..
    ```
3.  **Compilar el código y los tests:**
    ```bash
    cmake --build .
    ```
4.  **Ejecutar los tests:**
    ```bash
    ctest --verbose
    ```

### 

Se han añadido 5 tests unitarios en Python (test_functions.py) que replican y amplían la lógica de las funciones de C++.

Los casos probados son:

1-Suma sin desbordamiento.

2-Suma con desbordamiento.

3-Multiplicación simple.

4-Rotación de bits simple a la izquierda.

5-Rotación completa de 32 bits que devuelve el número original.

### Descripcion detallada de los tests

Los tests se encuentran en test_functions.py y verifican la lógica de desbordamiento en Python (usando ctypes para simular la aritmética de 32 bits sin signo):

test_add_no_wrap: Verifica la suma simple de 100 + 50 = 150.

test_add_with_wrap: Prueba el desbordamiento explícito en la suma (UINT_MAX + 2 = 1).

test_mul_no_wrap: Verifica la multiplicación simple de 10 * 10 = 100.

test_shift_simple_left_rotation: Prueba la rotación a la izquierda con un caso sencillo (1 rotado 1 bit = 2).

test_shift_full_rotation: Verifica que una rotación completa (32 bits) de cualquier número lo mantiene igual (12345 rotado 32 veces = 1234




