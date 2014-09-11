#include "Iterator.h"
#include "Aggregate.h"

#include <iostream>

using namespace std;

int main(void)
{
	Aggregate *ag = new ConcreteAggregate();
	Iterator *it = new ConcreateIterator(ag);

	for (; !it->IsDone(); it->Next())
	{
		cout << it->CurrentItem() << endl;
	}

	return 0;
}
