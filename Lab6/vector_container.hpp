#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include <iostream>
#include <vector>

#include "container.hpp"
#include "base.hpp"
#include "sort.hpp"

using namespace std;

class VectorContainer : public Container
{
	protected:
		vector<Base*> baseVector;
	public:
		VectorContainer();	
		VectorContainer(Sort* sort_function);
		void sort();
		void add_element(Base* element);
		void print();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};
#endif
			
