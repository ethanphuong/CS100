#include "gtest/gtest.h"
#include "../header/rectangle.hpp"
Rectangle rect(2,8);
Rectangle rect1(9,3);
Rectangle rect2(8,5);
TEST(ConstructTest1,Const1){

	EXPECT_EQ(rect.get_width(),2);
}
TEST(ConstructTest1,Const2){
	EXPECT_EQ(rect.get_height(),8);
}

TEST(ConstructTest2,Const3){

	EXPECT_EQ(rect1.get_width(),9);
}

TEST(ConstructTest2,Const4){

	EXPECT_EQ(rect1.get_height(),3);
}

TEST(AreaTest,Area1){

	EXPECT_EQ(rect.area(),16);
}

TEST(AreaTest,Area2){

	EXPECT_EQ(rect1.area(),27);
}

TEST(AreaTest,Area3){

	EXPECT_EQ(rect2.area(),40);
}

TEST(PerimeterTest,Perimeter1){

	EXPECT_EQ(rect.perimeter(),20);
}

TEST(PerimeterTest,Perimeter2){

	EXPECT_EQ(rect1.perimeter(),24);
}


TEST(PerimeterTest,Perimeter3){

	EXPECT_EQ(rect2.perimeter(),26);
}

int main(int argc,char **argv){
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}

