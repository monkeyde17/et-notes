#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	// this is a commond
	cin << a << b;
	cout << a + b << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "look out" << endl;
	}

	auto a = [](int, int) -> int
	{
		cout << a << endl;	
	};
	return 0;
}
