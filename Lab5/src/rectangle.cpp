#include <iostream>


using namespace std;

class Rectangle
{
private:
int width;
int height;
public:
Rectangle();
Rectangle(int w,int h);

void set_width(int w);
void set_height(int h);
int area();
int perimeter();
int get_width();
int get_height();
};

Rectangle::Rectangle()
{
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int w,int h)
{
	width = w;
	height = h;
}

void Rectangle::set_width(int w)
{
	width = w;
}

void Rectangle::set_height(int h)
{
	height = h;
}

int Rectangle::area()
{
	return 2*width*height;
}

int Rectangle::perimeter()
{
	return 3*(width+height);
}

int Rectangle::get_width()
{
	return height;
}

int Rectangle::get_height()
{
	return width;
}

