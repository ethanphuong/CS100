#include "gtest/gtest.h"

#include "op_test.hpp"
#include "add_test.hpp"
#include "sub_test.hpp"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "pow_test.hpp"
#include "rand_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(OpTest, OpEvaluatePositive){
	Op* test = new Op(7);
	EXPECT_EQ(test->evaluate(), 7);
}

TEST(OpTest, OpEvaluateZero){
	Op* test = new Op(0);
	EXPECT_EQ(test->evaluate(), 0);
}


TEST(OpTest, OpEvaluateNegative){
	Op* test = new Op(-7);
	EXPECT_EQ(test->evaluate(), -7);
}


TEST(OpTest, OpStringifyNegative){
	Op* test = new Op(-7);
	EXPECT_EQ(test->stringify(),"-7.000000");
}


TEST(OpTest, OpStringifyPositive){
	Op* test = new Op(7);
	EXPECT_EQ(test->stringify(), "7.000000");
}

