#include <iostream>
#include "Invoker.h"
#include "Reciever.h"
#include "Command.h"

using namespace std;

int main(void)
{
	Reciever *rev = new Reciever();
	Command *cmd = new ConcreteCommand(rev);
	Invoker *inv = new Invoker(cmd);

	inv->Invoke();

	delete rev;
	delete inv;

	return 0;
}

