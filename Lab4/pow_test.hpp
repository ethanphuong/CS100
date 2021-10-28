#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"

TEST(PowTest, PowEvaluateNonZero){
    Base* value1 = new Op(8);
    Base* value2 = new Op(2);
    Pow* test = new Pow(value1, value2);
    EXPECT_EQ(test->evaluate(), 64);
}
TEST(PowTest, PowEvaluateZero) {
    Base* value1 = new Op(0);
    Pow* test  = new Pow(value1, value1);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowEvaluateNegative) {
    Base* value1 = new Op(-8);
    Base* value2 = new Op(2);
    Pow* test = new Pow(value1, value2);
    EXPECT_EQ(test->evaluate(), 64);
}

TEST(PowTest, PowStringTest) {
   Base* value1 = new Op(8);
   Pow* test = new Pow(value1, value1);
   EXPECT_EQ(test->stringify(), "(8.000000 ** 8.000000)");
}
#endif //__ADD_TEST_HPP__
