# test_functions.py
import pytest
from functions import wrap_function_add, wrap_function_mul, wrap_function_shift

UINT_MAX = 0xFFFFFFFF

# --- 5 casos de test ---

# 1. Test de suma sin desbordamiento
def test_add_no_wrap():
    assert wrap_function_add(100, 50) == 150

# 2. Test de suma CON desbordamiento
def test_add_with_wrap():
    assert wrap_function_add(UINT_MAX, 2) == 1

# 3. Test de multiplicación simple
def test_mul_no_wrap():
    assert wrap_function_mul(10, 10) == 100

# 4. Test de rotación de bits simple a la izquierda (CORREGIDO)
def test_shift_simple_left_rotation():
    # Rotar el número 1 (binario ...0001) un bit a la izquierda
    # debería dar como resultado 2 (binario ...0010).
    assert wrap_function_shift(1, 1) == 2

# 5. Test de rotación completa (32 bits)
def test_shift_full_rotation():
    assert wrap_function_shift(12345, 32) == 12345