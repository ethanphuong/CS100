#include <iostream>
#include <vector>
#include <list>
#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "factory.hpp"

using namespace std;

int main (int argv, char** argc)
{
	Factory* mainFactory = new Factory();

	Base* output = mainFactory->parse(argc, argv);

	if (output == nullptr)
	{
		cout << "got nullptr!" << endl;
	}
 
	else
	{
        	cout << "My string is: " << output->stringify() << endl;
        	cout << "My number is: " << output->evaluate() << endl;
        }
        return 0;        
}
