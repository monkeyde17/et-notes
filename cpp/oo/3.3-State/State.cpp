#include "State.h"
#include "Context.h"

#include <iostream>

using namespace std;

State::State() {}
State::~State() {}

void State::OperationInterface(Context *con)
{
	cout << "State::OperationInterface" << endl;
}

bool State::ChangeState(Context *con, State *st)
{
	con->ChangeState(st);
	return true;
}

void State::OperationChangeState(Context *con) {}

ConreateStateA::ConreateStateA() {}
ConreateStateA::~ConreateStateA() {}

void ConreateStateA::OperationInterface(Context *con)
{
	cout << "ConreateStateA::OperationInterface" << endl;
}

void ConreateStateA::OperationChangeState(Context *con)
{
	OperationInterface(con);

	this->ChangeState(con, new ConreateStateB());
}

ConreateStateB::ConreateStateB() {}
ConreateStateB::~ConreateStateB() {}

void ConreateStateB::OperationInterface(Context *con)
{
	cout << "ConreateStateB::OperationInterface" << endl;
}

void ConreateStateB::OperationChangeState(Context *con)
{
	OperationInterface(con);

	this->ChangeState(con, new ConreateStateA());
}


