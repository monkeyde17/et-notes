#include "Context.h"
#include "State.h"

#include <iostream>

using namespace std;

int main(void)
{
	State *st = new ConreateStateA();
	Context *con = new Context(st);
	con->OperationChangeState();
	con->OperationChangeState();
	con->OperationChangeState();

	if (con != NULL)
	{
		delete con;
		con = NULL;
	}

	if (st != NULL)
	{
		delete st;
		st = NULL;
	}

	return 0;
}
