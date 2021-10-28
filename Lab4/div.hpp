#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "op.hpp"

class Div: public Base{
protected:
	double lhs, rhs, divAnswer;
	std::string lhsString, rhsString, divString;
public:
	Div(Base* lhsOp, Base* rhsOp)
	{
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		divAnswer = lhs / rhs;
		return divAnswer;
	}

	virtual std::string stringify()
	{
		divString = "(" + lhsString + " / " + rhsString + ")";
		return divString;
	}
};
#endif
