#include "gtest/gtest.h"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "factory.hpp"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

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
	EXPECT_EQ(test->stringify(),"-7.000000");
}
TEST(OpTest, OpStringifyNegative){
	Op* test = new Op(-7);
	EXPECT_EQ(test->stringify(),"-7.000000");
}


TEST(OpTest, OpStringifyPositive){
	Op* test = new Op(7);
	EXPECT_EQ(test->stringify(), "7.000000");
}
TEST(AddTest, addition) {					
	Op* op1 = new Op(9);
	Op* op2 = new Op(3);
	Add* add1 = new Add(op1,op2);
	EXPECT_EQ(add1->evaluate(),12.0);
	EXPECT_EQ(add1->stringify(),"(9.000000 + 3.000000)");

}
TEST(SubTest, subtraction) {
        Op* op1 = new Op(7);
        Op* op2  = new Op(1);
        Sub* sub1 = new Sub(op1, op2);
	EXPECT_EQ(sub1->evaluate(), 6.0);
        EXPECT_EQ(sub1->stringify(), "(7.000000 - 1.000000)");

}
TEST(PowTest, power) {
        Op* op1 = new Op(4);
        Op* op2  = new Op(4);
        Pow* pow1 = new Pow(op1, op2);
        EXPECT_EQ(pow1->evaluate(), 256);
        EXPECT_EQ(pow1->stringify(), "(4.000000 ** 4.000000)");
}
TEST(MultTest, multiplication){

	Op* op1 = new Op(5);
	Op* op2 = new Op(2);
	Mult* mult1 = new Mult(op1, op2);
	EXPECT_EQ(mult1->evaluate(), 10.0);
	EXPECT_EQ(mult1->stringify(), "(5.000000 * 2.000000)");
	
	Op* op3 = new Op(-62.0);
	Op* op4 = new Op(0.0);
	Op* op5 = new Op(-23.0);

	Mult* mult2 = new Mult(op3, op4);
	EXPECT_EQ(mult2->evaluate(), 0.0);
	EXPECT_EQ(mult2->stringify(), "(-62.000000 * 0.000000)");

	Mult* mult3 = new Mult(op3, op5);
	EXPECT_EQ(mult3->evaluate(),1426.0);
	EXPECT_EQ(mult3->stringify(), "(-62.000000 * -23.000000)");
}			

TEST(DivTest, division){
	Op* op1 = new Op(5);
	Op* op2 = new Op(10);

	Div*  div1  = new Div(op1, op2);
	EXPECT_EQ(div1->evaluate(), 0.5);
	EXPECT_EQ(div1->stringify(), "(5.000000 / 10.000000)");

	Op* op3 = new Op(0.0);
        Op* op4 = new Op(-10.0);
        Op* op5 = new Op(-34.0);
	
	Div* div2 = new Div(op3, op4);
        EXPECT_EQ(div2->evaluate(), 0.0);
        EXPECT_EQ(div2->stringify(), "(0.000000 / -10.000000)");

	Div* div3 = new Div(op5, op4);
	EXPECT_EQ(div3->evaluate(), 3.4);
	EXPECT_EQ(div3->stringify(), "(-34.000000 / -10.000000)");
}

TEST(Calculatortest,divide) {

	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "50"; test_val[2] = "/" ; test_val[3] = "2";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 4);
	EXPECT_EQ(test->evaluate(),25.0);
	EXPECT_EQ(test->stringify(),"(50.000000 / 2.000000)");
}
 					     
TEST(Calculatortest, subtract) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "700"; test_val[2] = "-" ; test_val[3] = "150";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 4);
	EXPECT_EQ(test->stringify(),"(700.000000 - 150.000000)");
	EXPECT_EQ(test->evaluate(),550);
}

TEST(Calculatortest, addthensub) {
	char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "+" ; test_val[3] = "7"; test_val[4] = "-"; test_val[5] = "4";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 6);
	EXPECT_EQ(test->stringify(),"((5.000000 + 7.000000) - 4.000000)");
	EXPECT_EQ(test->evaluate(),8);
}
TEST(Calculatortest, multiply) {
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "15"; test_val[2] = "\*" ; test_val[3] = "4";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 4);
	EXPECT_EQ( test->stringify(),"(15.000000 * 4.000000)");
	EXPECT_EQ( test->evaluate(),60);
}

TEST(Calculatortest, pow){
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "5"; test_val[2] = "\**" ; test_val[3] = "3";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 4);
	EXPECT_EQ(test->stringify(),"(5.000000 ** 3.000000)");
	EXPECT_EQ(test->evaluate(),125);
}

TEST(Calculatortest, powbyzero){
	char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "7"; test_val[2] = "\**" ; test_val[3] = "0";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 4);
	EXPECT_EQ(test->stringify(),"(7.000000 ** 0.000000)");
	EXPECT_EQ(test->evaluate(),1);
}

TEST(Calculatorest, num) {
	char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "365";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 2);
	EXPECT_EQ( test->stringify(),"365.000000");
	EXPECT_EQ( test->evaluate(),365);
}

TEST(Calculatortest, null){
	char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "fillertext";
	Factory* factory = new Factory();
	Base* test = factory->parse(test_val, 2);
	ASSERT_TRUE(test == nullptr);
	cout << "Try again, your input is invalid" << endl;
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
