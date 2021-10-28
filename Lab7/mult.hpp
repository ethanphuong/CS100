#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"

class Mult: public Base{
protected:
	double lhs, rhs, multAnswer;
	std::string lhsString, rhsString, multString;
public:
	Mult(Base* lhsOp, Base* rhsOp)
	{
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		multAnswer = lhs * rhs;
		return multAnswer;
	}

	virtual std::string stringify()
	{
		multString = "(" + lhsString + " * " + rhsString + ")";
		return multString;
	}
};
#endif

