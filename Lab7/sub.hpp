#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

class Sub: public Base{
protected:
	double lhs, rhs, subAnswer;
	std::string lhsString, rhsString, subString;
public:
	Sub(Base* lhsOp, Base* rhsOp)
	{
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		subAnswer = lhs - rhs;
		return subAnswer;
	}

	virtual std::string stringify()
	{
		subString = "(" + lhsString + " - " + rhsString + ")";
		return subString;
	}
};
#endif
