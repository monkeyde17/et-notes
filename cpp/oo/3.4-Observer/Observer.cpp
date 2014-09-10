#include "Subject.h"
#include "Observer.h"

#include <iostream>
using namespace std;

Observer::Observer()
{
	_st = '\0';
}

Observer::~Observer()
{

}

ConcreteObserverA::ConcreteObserverA(Subject *sub)
{
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA()
{
	_sub->Detach(this);
	if (_sub != NULL)
	{
		delete _sub;
		_sub = NULL;
	}
}

Subject *ConcreteObserverA::GetSubject()
{
	return _sub;
}

void ConcreteObserverA::PrintInfo()
{
	cout << "ConcreteObserverA Observer ... " << _sub->GetState() << endl;
}

void ConcreteObserverA::Update(Subject *sub)
{
	_st = sub->GetState();
	PrintInfo();
}

ConcreteObserverB::ConcreteObserverB(Subject *sub)
{
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB()
{
	_sub->Detach(this);
	if (_sub != NULL)
	{
		delete _sub;
		_sub = NULL;
	}
}

Subject* ConcreteObserverB::GetSubject()
{
	return _sub;
}

void ConcreteObserverB::PrintInfo()
{
	cout << "ConcreteObserverB Observer ... " << _sub->GetState() << endl;
}

void ConcreteObserverB::Update(Subject *sub)
{
	_st = sub->GetState();
	PrintInfo();
}


