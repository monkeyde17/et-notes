#ifndef __INVOKER_H__
#define __INVOKER_H__

class Command;

class Invoker
{
public:
	Invoker(Command *cmd);
	~Invoker();
	void Invoke();

private:
	Command *_cmd;
};

#endif
