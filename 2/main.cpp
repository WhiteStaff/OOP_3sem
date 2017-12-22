#include "StatisticMultiset.h"
#include <iostream>

using namespace std;

int main()
{
	StatisticMultiset<double> Example;
	Example.AddNum(3.4);
	//cout << Example.GetAvg() << endl;
	Example.AddNum(5.4);
	Example.AddNum(2.6);
	//cout << Example.GetAvg() << endl;
	cout << Example.GetMax() << endl;
}
