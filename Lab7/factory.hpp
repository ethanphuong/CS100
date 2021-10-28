#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class base;

class Factory 
{
public:
	Factory(){ };
	Base* parse(char** input, int length)
	{
        queue<char*> queue1;
        stack<char*> stack1;
        string operation;

        for (int i = 1; i < length; ++i)
	{
        	operation = static_cast<string>(input[i]);
        	if (isdigit(operation.at(0)))
		{
        		queue1.push(input[i]);
          	}
        	else if (operation == "+" || operation == "-" || operation == "*" || operation == "/" || operation == "**")
		{
        		while(!stack1.empty())
			{
              			queue1.push(stack1.top());
              			stack1.pop();
            		}
            		stack1.push(input[i]);
		}
        	else
		{
        		cout << "Invalid input" << endl;
            		return nullptr;
        	}
        }
        while(!stack1.empty())
	{
          	queue1.push(stack1.top());
          	stack1.pop();
        }

        queue<Base*> queue2;
        Base* temp1;
        Base* temp2;
        Base* temp3;
        double temp4;

        while(!queue1.empty())
	{
          	operation = static_cast<string>(queue1.front());
          	if (operation == "+")
		{
           		temp2 = queue2.front();
           		queue2.pop();
           		temp3 = queue2.front();
           		queue2.pop();
           		temp1 = new Add(temp2, temp3);
           		queue2.push(temp1);
           		queue1.pop();
          	}
          	else if (operation == "-")
		{
           		temp2 = queue2.front();
           		queue2.pop();
           		temp3 = queue2.front();
           		queue2.pop();
           		temp1 = new Sub(temp2, temp3);
           		queue2.push(temp1);
           		queue1.pop();
          	}
          	else if (operation == "*")
		{
           		temp2 = queue2.front();
           		queue2.pop();
           		temp3 = queue2.front();
           		queue2.pop();
           		temp1 = new Mult(temp2, temp3);
           		queue2.push(temp1);
           		queue1.pop();
          	}
          	else if (operation == "/")
		{
           		temp2 = queue2.front();
           		queue2.pop();
           		temp3 = queue2.front();
           		queue2.pop();
           		temp1 = new Div(temp2, temp3);
           		queue2.push(temp1);
           		queue1.pop();
          	}
          	else if (operation == "**")
		{
           		temp2 = queue2.front();
           		queue2.pop();
           		temp3 = queue2.front();
           		queue2.pop();
           		temp1 = new Pow(temp2, temp3);
           		queue2.push(temp1);
           		queue1.pop();
          	}
          	else
		{
            		temp4 = stod(operation);
            		temp1 = new Op(temp4);
            		queue1.pop();
            		queue2.push(temp1);
          	}

        }
       	return queue2.front();
	}
};

#endif
