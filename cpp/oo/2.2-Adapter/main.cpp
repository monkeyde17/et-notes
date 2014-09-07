#include "Adapter.h"

#include <iostream>
using namespace std;


int main(void)
{
	Target *adt = new Adapter();

	adt->Request();
	
	return 0;
}
