#include "StaticStack.h"
#include <exception>
#include <iostream>
using namespace std;
int main()
{
	StaticStack <int>SS;
	SS.push(10);
	SS.push(20);
	cout << SS.top() << endl;
	try
	{
		SS.Pop();
	}
	catch(exception e)
	{
		cout << e.what();
	}
	cout << SS.top();
	cout << SS.Empty();
	return 0;
}
