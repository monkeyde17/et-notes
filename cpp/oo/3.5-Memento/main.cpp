#include "Memento.h"
#include <iostream>

using namespace std;

int main(void)
{
	Originator *o = new Originator();
	o->SetState("old");
	o->PrintState();

	Memento *m = o->CreateMemento();
	o->SetState("new");
	o->PrintState();
	o->RestoreToMemento(m);
	o->PrintState();

	return 0;
}
