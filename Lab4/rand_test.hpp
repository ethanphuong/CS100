#ifndef __RAND_TEST_HPP__
#define __RAND_TEST_HPP__

#include "gtest/gtest.h"

#include "random.hpp"

TEST(RandTest, RandEvaluate){
    Random* test = new Random();
    EXPECT_TRUE(test->evaluate() < 100);
}

TEST(RandTest, RandStringEvaluate){
    Random* test = new Random();
    EXPECT_TRUE(test->evaluate() < 100);
}
#endif 
