#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <iostream>
#include <list>
#include "container.hpp"
#include "base.hpp"
#include "sort.hpp"

using namespace std;

class ListContainer : public Container
{	protected:
	list<Base*>::iterator Lit;
	list<Base*> listContainer;
	public:
		
		ListContainer();	
		ListContainer(Sort* sort_function);
		void sort();
		void add_element(Base* element);
		void print();
		void swap(int i, int j);
		Base* at(int i);
		int size();
};
#endif
