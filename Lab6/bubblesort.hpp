#ifndef __BUBBLESORT__HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class BubbleSort: public Sort{
public:
	BubbleSort();
	void sort(Container* container);
};

#endif
