#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include "Context.h"
#include <string>

using namespace std;

class AbstractExpression
{
public:
	virtual ~AbstractExpression();
	virtual void Interpret(const Context &c);
protected:
	AbstractExpression();
};

class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const string &statement);
	~TerminalExpression();
	void Interpret(const Context &c);

private:
	string _statement;
};

class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression *expression, int times);
	~NonterminalExpression();
	void Interpret(const Context &c);

private:
	AbstractExpression *_expression;
	int _times;
};
#endif
