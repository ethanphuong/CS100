#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <math.h>

class Pow: public Base{
protected:
	double lhs, rhs, powAnswer;
	std::string lhsString, rhsString, powString;
public:
	Pow(Base* lhsOp, Base* rhsOp)
	{
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		powAnswer = pow(lhs, rhs);
		return powAnswer;
	}

	virtual std::string stringify()
	{
		powString = "(" + lhsString + " ** " + rhsString + ")";
		return powString;
	}
};
#endif
