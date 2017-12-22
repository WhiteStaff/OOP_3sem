#include "fun.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Showplace a(string("aaa"), string("bbb"), 1, 2);
	cout << a.GetName() << endl;
	cout << a.GetDescription() << endl;
	cout << a.GetDistance(4, 6) << endl;

}