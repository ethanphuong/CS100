#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero){
    Base* value1 = new Op(8);
    Mult* test = new Mult(value1, value1);
    EXPECT_EQ(test->evaluate(), 64);
}
TEST(MultTest, MultEvaluateZero) {
    Base* value1 = new Op(0);
    Mult* test  = new Mult(value1, value1);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultEvaluateNegative) {
    Base* value1 = new Op(-8);
    Mult* test = new Mult(value1, value1);
    EXPECT_EQ(test->evaluate(), 64);
}

TEST(MultTest, MultAddEvaluate){
    Base* value1 = new Op(8);
    Base* value2 = new Op(2);
    Add* addTest = new Add(value1, value2);
    Mult* test = new Mult(addTest, value1);
    EXPECT_EQ(test->evaluate(), 80);
}

TEST(MultTest, MultStringTest) {
   Base* value1 = new Op(8);
   Mult* test = new Mult(value1, value1);
   EXPECT_EQ(test->stringify(), "(8.000000 * 8.000000)");
}
#endif //__MULT_TEST_HPP__
