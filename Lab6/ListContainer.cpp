#include "ListContainer.hpp"
using namespace std;
                
ListContainer::ListContainer(): Container(){}
ListContainer::ListContainer(Sort* sort_function){}
void ListContainer::sort()
{
sort_function->sort(this);
}
void ListContainer::add_element(Base* element)
{
listContainer.push_back(element);
}
void ListContainer::print()
{
for (unsigned int i=0; i<listContainer.size();i++)
	{
	cout << this->at(i)->evaluate()<<endl;
	}
}
void ListContainer::swap(int i, int j)
{
                list<Base*>::iterator Lit_i = listContainer.begin();
		list<Base*>::iterator Lit_j = listContainer.begin();
		Base* temp;

		advance(Lit_i, i);
		advance(Lit_j, j);
		
		temp = *Lit_i;
		*Lit_i = *Lit_j;
		*Lit_j = temp;
}
Base* ListContainer::at(int i)
{
list<Base*>::iterator Lit = listContainer.begin();
advance(Lit,i);
return *Lit;
}
int ListContainer::size()
{
return listContainer.size();
}

