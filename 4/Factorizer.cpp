#include "Factorizer.h"
#include <cmath>
#include <iostream>
#include <string>

Factorizer::Factorizer(uint64_t num)
{
	while (num % 2 == 0)
	{
		num /= 2;
		row.push_back(2);
	}
	for (size_t i = 3; i <= num; i += 2)
	{
		while (num % i == 0)
		{
			num /= i;
			row.push_back(i);
		}
	}
	if (row.size() == 0)
	{
		row.push_back(num);
	}
}

void Factorizer::Clean()
{
	row.clear();
}

std::string Factorizer::Out()
{
	std::string out;
	for (auto q : row)
	{
		out += std::to_string(q);
		out += " ";
	}
	Clean();
	return out;
}
