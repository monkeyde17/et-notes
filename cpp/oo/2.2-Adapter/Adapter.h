#ifndef __ADAPTER_H__
#define __ADAPTER_H__

class Target
{
public:
	Target();
	virtual ~Target();

	virtual void Request();
};

class Adaptee
{
public:
	Adaptee();
	~Adaptee();

	void SpecificRequest();

};

class Adapter : public Target, private Adaptee
{
public:
	Adapter();
	~Adapter();

	void Request();
};
#endif
