#include "AbstractFactory.h"
#include "Product.h"

#include <iostream>

using namespace std;

AbstractFactory::AbstractFactory() {}
AbstractFactory::~AbstractFactory() {}

/* factory 1 */
ConcreateFactory1::ConcreateFactory1() {}
ConcreateFactory1::~ConcreateFactory1() {}

AbstractProductA* ConcreateFactory1::CreateProductA()
{
	return new ProductA1();
}
AbstractProductB* ConcreateFactory1::CreateProductB()
{
	return new ProductB1();
}

/* factory 2 */
ConcreateFactory2::ConcreateFactory2() {}
ConcreateFactory2::~ConcreateFactory2() {}

AbstractProductA* ConcreateFactory2::CreateProductA()
{
	return new ProductA2();
}

AbstractProductB* ConcreateFactory2::CreateProductB()
{
	return new ProductB2();
}

