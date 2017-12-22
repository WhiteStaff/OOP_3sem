#include "StatisticMultiset.h"
#include <iostream>
#include <algorithm>

void StatisticMultiset::AddNum(int num)
{
	std::cin >> num;
	numbers.push_back(num);
}
int StatisticMultiset::GetMax()
{
	return std::max_element(*numbers.begin(), *numbers.end());
}
int StatisticMultiset::GetMin()
{
	return std::min_element(*numbers.begin(), *numbers.end());
}
float StatisticMultiset::GetAvg()
{
	int sum;
	for (auto q : numbers)
	{
		sum += q;
	};
	return sum / numbers.size();
}
int  StatisticMultiset::GetCountAbove(float threshold)
{
	int i;
	for (auto q : numbers)
	{
		if (threshold < q) i++;
	};
	return i;
}
int  StatisticMultiset::GetCountUnder(float threshold)
{
	int i;
	for (auto q : numbers)
	{
		if (threshold > q) i++;
	};
	return i;
}