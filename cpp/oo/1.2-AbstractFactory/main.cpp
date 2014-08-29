#include <iostream>
#include "AbstractFactory.h"

using namespace std;

int main(void)
{
	AbstractFactory* cf1 = new ConcreateFactory1();

	cf1->CreateProductA();
	cf1->CreateProductB();

	AbstractFactory* cf2 = new ConcreateFactory2();

	cf2->CreateProductA();
	cf2->CreateProductB();

	return 0;
}

