#ifndef _ABSTRACTFACTORY_H_
#define _ABSTRACTFACTORY_H_

class AbstractProductA;
class AbstractProductB;

class AbstractFactory
{
public:
	virtual ~AbstractFactory();
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;

protected:
	AbstractFactory();
};

class ConcreateFactory1 : public AbstractFactory
{
public:
	ConcreateFactory1();
	~ConcreateFactory1();

	AbstractProductA* CreateProductA();
	AbstractProductB* CreateProductB();
};

class ConcreateFactory2 : public AbstractFactory
{
public:
	ConcreateFactory2();
	~ConcreateFactory2();
	AbstractProductA* CreateProductA();
	AbstractProductB* CreateProductB();
};


#endif

