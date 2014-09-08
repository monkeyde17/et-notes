#ifndef __STATE_H__
#define __STATE_H__

class Context;

class State
{
public:
	State();
	virtual	~State();
	virtual void OperationInterface(Context *) = 0;
	virtual void OperationChangeState(Context *) = 0;

protected:
	bool ChangeState(Context *con, State* st);
};

class ConreateStateA : public State
{
public:
	ConreateStateA();
	virtual ~ConreateStateA();
	virtual void OperationInterface(Context *);
	virtual void OperationChangeState(Context *);
};

class ConreateStateB : public State
{
public:
	ConreateStateB();
	virtual ~ConreateStateB();
	virtual void OperationInterface(Context *);
	virtual void OperationChangeState(Context *);
};

#endif
