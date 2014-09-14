#include "Invoker.h"
#include "Command.h"

#include <iostream>

using namespace std;

Invoker::Invoker(Command *cmd)
{
	_cmd = cmd;
}

Invoker::~Invoker()
{
	if (_cmd)
	{
		cout << "delete _cmd" << endl;
		delete _cmd;
		_cmd = NULL;
	}
	cout << "~Invoker" << endl;
}

void Invoker::Invoke()
{
	_cmd->Excute();
}
