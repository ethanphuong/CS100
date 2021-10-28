#include "vector_container.hpp"

using namespace std;

VectorContainer::VectorContainer(): Container(){}

VectorContainer::VectorContainer(Sort* sort_function) {};
		
void VectorContainer::sort()
{
	sort_function->sort(this);
}
void VectorContainer::add_element(Base* element)
{
	baseVector.push_back(element);
}
void VectorContainer::print()
{
	for(unsigned int i = 0; i < baseVector.size(); ++i)
	{
		cout << baseVector.at(i)->evaluate() << endl;
	}
}
void VectorContainer::swap(int i,int j)
{
	Base* temp = baseVector.at(i);
	baseVector.at(i) = baseVector.at(j);
	baseVector.at(j) = temp;
}
Base* VectorContainer::at(int i)
{
	return baseVector.at(i);
}
int VectorContainer::size()
{
	return baseVector.size();
}

