#pragma once
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

template <class T>
class StatisticMultiset
{
public:
	StatisticMultiset()
	{

	}
	~StatisticMultiset()
	{

	}
	void AddNum(T num)
	{
		numbers.insert(num);
	}
	void AddNum(const std::multiset<T>& getnumbers)
	{
		for (auto q : getnumbers)
		{
			AddNum(q);
		}
	}
	void AddNums(const StatisticMultiset& a_stat_set)
	{
		for (auto q : a_stat_set.numbers)
		{
			AddNum(q);
		}
	}
	void AddFileNums(const char* file)
	{
		std::ifstream fin(file);
		double in;
		while (fin.good())
		{
			fin >> in;
			AddNum(int(in));
		}
	}
	T GetMax()
	{
		if (numsizeforMax != numbers.size())
		{
			numsizeforMax = numbers.size();
			Max = *numbers.crbegin();
		}
		return Max;
	}
	T GetMin()
	{
		if (numsizeforMin != numbers.size())
		{
			numsizeforMin = numbers.size();
			Min = *numbers.begin();
		}
		return Min;
	}
	double GetAvg()
	{
		if (size != numbers.size())
		{
			double sum = 0;
			for (auto q : numbers)
			{
				sum += q;
			}
			Avg = sum / numbers.size();	
		}
		return Avg;
	}
	T GetCountUnder(float threshold)
	{
		if ((LastThresholdUnder != threshold) || (numsizeforUnder != numbers.size()))
		{
			numsizeforUnder = numbers.size();
		}
		LastThresholdUnder = threshold;
		return std::distance(numbers.begin(), numbers.lower_bound(threshold));
	}
	T GetCountAbove(float threshold)
	{
		if ((LastThresholdAbove != threshold) || (numsizeforAbove != numbers.size()))
		{
			numsizeforAbove = numbers.size();
		}
		LastThresholdAbove = threshold;
		return std::distance(numbers.upper_bound(threshold), numbers.end());
	}
private:
	std::multiset <T> numbers;
	double Avg, LastThresholdUnder;
	T Min, Max;
	mutable int numsizeforMax = 0, numsizeforMin = 0, size = 0, numsizeforUnder = 0, numsizeforAbove = 0, LastThresholdAbove = 0;
};