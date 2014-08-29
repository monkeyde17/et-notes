#include <iostream>
#include "Singleton.h"

using namespace std;

int main(void)
{
	Singleton *sgn = Singleton::Instance();
	return 0;
}
