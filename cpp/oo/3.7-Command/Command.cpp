#include <iostream>
#include "Reciever.h"
#include "Command.h"

using namespace std;

Command::Command() {}
Command::~Command() {}

void Command::Excute() {}

ConcreteCommand::ConcreteCommand(Reciever *rev)
{
	_rev = rev;
}

ConcreteCommand::~ConcreteCommand()
{
	if (_rev)
	{
		cout << "delete _rev ... " << endl;
		delete _rev;
		_rev = NULL;
	}
	cout << "~ConcreteCommand ... " << endl;
}

void ConcreteCommand::Excute()
{
	_rev->Action();
	cout << "ConcreteCommand::Excute ... " << endl;
}
