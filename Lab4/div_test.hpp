#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "sub.hpp"

TEST(DivTest, DivEvaluateNonZero){
    Base* value1 = new Op(8);
    Base* value2 = new Op(4);
    Div* test = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), 2);
}
TEST(DivTest, DivEvaluateZero) {
    Base* value1 = new Op(0);
    Base* value2 = new Op(8);
    Div* test  = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateNegative) {
    Base* value1 = new Op(-8);
    Base* value2 = new Op(2);
    Div* test = new Div(value1, value2);
    EXPECT_EQ(test->evaluate(), -4);
}

TEST(DivTest, DivSubEvaluate){
    Base* value1 = new Op(8);
    Base* value2 = new Op(4);
    Sub* subTest = new Sub(value1, value2);
    Div* test = new Div(value1, subTest);
    EXPECT_EQ(test->evaluate(), 2);
}

TEST(DivTest, DivStringTest) {
   Base* value1 = new Op(8);
   Div* test = new Div(value1, value1);
   EXPECT_EQ(test->stringify(), "(8.000000 / 8.000000)");
}
#endif //__ADD_TEST_HPP__
