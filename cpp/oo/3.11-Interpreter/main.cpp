#include "Context.h"
#include "Interpret.h"

#include <iostream>

using namespace std;

int main(void)
{
	Context *c = new Context();
	AbstractExpression *te = new TerminalExpression("hello");
	AbstractExpression *nte = new NonterminalExpression(te, 2);
	nte->Interpret(*c);
	return 0;
}
