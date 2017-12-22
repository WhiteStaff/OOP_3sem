// 3205_Malinin_Alexandr 
#pragma once
#include <vector>
#include <string>

template <class T>
void myfun(std::vector<T>& a)
{
	if (a.size() % 2 == 0)
	{
		int middle = a.size() / 2;
		for (int i = 0; i < a.size() / 2; i++)
		{
			swap(a[i], a[middle + i]);
		}
	}
	else
	{
		int middle = (a.size() / 2) + 1;
		for (int i = 0; i < (a.size() / 2); i++)
		{
			swap(a[i], a[middle + i]);
		}
	}
}

class Showplace
{
public:
	Showplace(const std::string& _name,const  std::string& _description, double a, double b);
	std::string GetName();
	std::string GetDescription();
	double GetDistance(double a, double b);
private:
	std::string name, description;
	double x, y;
};