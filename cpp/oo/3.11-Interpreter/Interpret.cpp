#include "Interpret.h"
#include <iostream>

using namespace std;

AbstractExpression::AbstractExpression() {}
AbstractExpression::~AbstractExpression() {}
void AbstractExpression::Interpret(const Context &c) {}

TerminalExpression::TerminalExpression(const string &statement)
{
	_statement = statement;
}

TerminalExpression::~TerminalExpression() {}

void TerminalExpression::Interpret(const Context &c)
{
	cout << _statement << " TerminalExpression" << endl;
}

NonterminalExpression::NonterminalExpression(AbstractExpression *expression, int times)
{
	_expression = expression;
	_times = times;
}

NonterminalExpression::~NonterminalExpression() {}

void NonterminalExpression::Interpret(const Context &c)
{
	for (int i = 0; i < _times; i++)
	{
		_expression->Interpret(c);
	}
}

