#include "bubblesort.hpp"
#include "container.hpp"
using namespace std;
BubbleSort::BubbleSort() : Sort() {}
void BubbleSort::sort(Container* sortList)
{

  int i, j, flag = 1;                
      int numLength = sortList->size(); 
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (sortList->at(j)->evaluate() > sortList->at(j+1)->evaluate())  
              { 
                    sortList->swap(j,j+1);
                    flag = 1;              
               }
          }
     }
     return;  
}
