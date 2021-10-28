#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "add.hpp"
#include "mult.hpp"

TEST(AddTest, AddEvaluateNonZero){
    Base* value1 = new Op(8);
    Add* test = new Add(value1, value1);
    EXPECT_EQ(test->evaluate(), 16);
}
TEST(AddTest, AddEvaluateZero) {
    Base* value1 = new Op(0);
    Add* test  = new Add(value1, value1);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddEvaluateNegative) {
    Base* value1 = new Op(-8);
    Add* test = new Add(value1, value1);
    EXPECT_EQ(test->evaluate(), -16);
}

TEST(AddTest, AddMultEvaluate){
    Base* value1 = new Op(8);
    Base* value2 = new Op(2);
    Mult* multTest = new Mult(value1, value2);
    Add* test = new Add(value1, multTest);
    EXPECT_EQ(test->evaluate(), 24);
}

TEST(AddTest, AddStringTest) {
   Base* value1 = new Op(8);
   Add* test = new Add(value1, value1);
   EXPECT_EQ(test->stringify(), "(8.000000 + 8.000000)");
}
#endif //__ADD_TEST_HPP__
