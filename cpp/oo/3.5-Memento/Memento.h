#ifndef _MEMENTO_H_
#define _MEMENTO_H_

#include <string>
using namespace std;

class Memento;

class Originator
{
public:
	typedef string State;

	Originator();
	Originator(const State &sdt);
	~Originator();
	Memento* CreateMemento();
	void SetMemento(Memento* men);
	void RestoreToMemento(Memento *mt);
	State GetState();
	void SetState(const State &sdt);
	void PrintState();

private:
	State _sdt;
	Memento *_mt;
};

class Memento
{
private:
	friend class Originator;
	typedef string State;

	Memento();
	Memento(const State &std);
	~Memento();

	void SetState(const State &std);
	State GetState();
private:
	State _sdt;
};

#endif
