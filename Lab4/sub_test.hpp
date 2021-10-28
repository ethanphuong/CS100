#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "div.hpp"

TEST(SubTest, SubEvaluateNonZero){
    Base* value1 = new Op(8);
    Base* value2 = new Op(2);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), 6);
}
TEST(SubTest, SubEvaluateZero) {
    Base* value1 = new Op(0);
    Sub* test  = new Sub(value1, value1);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubEvaluateNegative) {
    Base* value1 = new Op(-8);
    Base* value2 = new Op(-2);
    Sub* test = new Sub(value1, value2);
    EXPECT_EQ(test->evaluate(), -6);
}

TEST(SubTest, SubDivEvaluate){
    Base* value1 = new Op(8);
    Base* value2 = new Op(2);
    Div* divTest = new Div(value1, value2);
    Sub* test = new Sub(value1, divTest);
    EXPECT_EQ(test->evaluate(), 4);
}

TEST(SubTest, SubStringTest) {
   Base* value1 = new Op(8);
   Sub* test = new Sub(value1, value1);
   EXPECT_EQ(test->stringify(), "(8.000000 - 8.000000)");
}
#endif //__SUB_TEST_HPP__
