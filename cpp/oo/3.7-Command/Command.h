#ifndef __COMMAND_H__
#define __COMMAND_H__

class Reciever;

class Command
{
public:	
	virtual ~Command();
	virtual void Excute() = 0;

protected:
	Command();
};

class ConcreteCommand : public Command
{
public:
	ConcreteCommand(Reciever *rev);
	~ConcreteCommand();
	void Excute();

private:
	Reciever *_rev;
};

#endif
