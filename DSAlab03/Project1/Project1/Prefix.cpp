#include "Prefix.h"
#include <iostream>
using namespace  std;
int main() {
	Prefix pre;
	string s = "(2+3)*4";
	string prefix=pre.Evaluate(s);
	cout << prefix << endl;
	cout << pre.Calculate(prefix);

	return 0;
}
