# functions.py
import ctypes

def wrap_function_add(a, b):
    """Suma dos enteros sin signo de 32 bits, permitiendo el desbordamiento (wrapping)."""
    return ctypes.c_uint32(a + b).value

def wrap_function_mul(a, b):
    """Multiplica dos enteros sin signo de 32 bits, permitiendo el desbordamiento."""
    return ctypes.c_uint32(a * b).value

def wrap_function_shift(a, b):
    """Rota los bits de un entero de 32 bits 'a' hacia la izquierda 'b' posiciones."""
    b = b % 32
    return ctypes.c_uint32((a << b) | (a >> (32 - b))).value