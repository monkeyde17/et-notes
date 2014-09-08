#include "Context.h"
#include "State.h"

Context::Context() {}
Context::Context(State *state) 
{
	this->_state = state;
}

Context::~Context() {}

void Context::OperationInterface()
{
	_state->OperationInterface(this);
}

bool Context::ChangeState(State *state)
{
	this->_state = state;
	return true;
}

void Context::OperationChangeState()
{
	_state->OperationChangeState(this);
}


