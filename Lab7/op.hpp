#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    protected:
	double doubleNumber;
	std::string stringNumber;
    public:
        Op(double value) : Base()
 	{
		doubleNumber = value;
		stringNumber = std::to_string(value);
	}
	
	virtual double evaluate()
	{
		return doubleNumber;
	}
	
	virtual std::string stringify()
	{
		return stringNumber;
	}
};		

#endif //__OP_HPP__

