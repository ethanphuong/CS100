#include "selection_sort.hpp"

using namespace std;

SelectionSort::SelectionSort() : Sort() {}

void SelectionSort::sort(Container* sortList)
{
	unsigned int i, j, min_idx;
	int numLength = sortList->size();
	for(i = numLength - 1; i > 0; i--)
	{
		min_idx = 0;
		for(j = 1; j <= i; j++)
		{
			if(sortList->at(j)->evaluate() > sortList->at(min_idx)->evaluate())
			{
				min_idx = j;
			}
		}
		sortList->swap(min_idx, i);	
	}
}

