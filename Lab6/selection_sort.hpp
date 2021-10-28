#ifndef __SELECTION_SORT__HPP__
#define __SELECTION_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class SelectionSort: public Sort{
public:
	SelectionSort();
	void sort(Container* container);
};

#endif
