#include "Functions.h" // ¡Incluimos el nuevo header, no el .cpp!
#include <gtest/gtest.h>
#include <limits.h>

TEST(WrapAddFunctionTest, NonWrappingNums) {
    ASSERT_EQ(9, wrapFunctionAdd(3, 6));
}

TEST(WrapAddFunctionTest, WrappingNums) {
    ASSERT_EQ(0, wrapFunctionAdd(UINT_MAX, 1));
}

TEST(WrapMulFunctionTest, NonWrappingMulNums) {
    ASSERT_EQ(18, wrapFunctionMul(3, 6));
}

TEST(WrapMulFunctionTest, WrappingMulNums) {
    ASSERT_EQ(1, wrapFunctionMul(UINT_MAX, UINT_MAX));
}

TEST(WrapShiftFunctionTest, RotateLeft) {
    ASSERT_EQ(4, wrapFunctionShift(2, 1));
}

TEST(WrapShiftFunctionTest, RotateWithWrap) {
    ASSERT_EQ(1, wrapFunctionShift(1, 32));
}