#include <iostream>
#include "Prototype.h"

using namespace std;

int main(void)
{
	Prototype *p = new ConcretePrototype();

	Prototype *p1 = p->Clone();

	return 0;
}
