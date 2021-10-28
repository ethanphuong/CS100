#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include "base.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Random : public Base {
    protected:
	double randomNumber;
	std::string stringNumber;
    public:
        Random() : Base()
	{
		srand(time(0));
		randomNumber = (rand() % 100);  
		stringNumber = std::to_string(randomNumber);
	}
	virtual double evaluate()
	{
		return randomNumber;
	}
	
	virtual std::string stringify()
	{
		return stringNumber;
	}
};		

#endif //__OP_HPP__
