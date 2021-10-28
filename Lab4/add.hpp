#ifndef __ADD__HPP__
#define __ADD__HPP__

#include "base.hpp"
#include "op.hpp"

class Add: public Base{
protected:
	double lhs, rhs, addAnswer;
	std::string lhsString, rhsString, addString;
public:
	Add(Base* lhsOp, Base* rhsOp)
	{
		lhs = lhsOp->evaluate();
		rhs = rhsOp->evaluate();
		lhsString = lhsOp->stringify();
		rhsString = rhsOp->stringify();
	}
	
	virtual double evaluate()
	{
		addAnswer = lhs + rhs;
		return addAnswer;
	}

	virtual std::string stringify()
	{
		addString = "(" + lhsString + " + " + rhsString + ")";
		return addString;
	}
};
#endif
