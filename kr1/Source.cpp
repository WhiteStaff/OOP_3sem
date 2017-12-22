// 3205_Malinin_Alexandr 
#include "fun.h"
#include <vector>
#include <iostream>
#include <string>
#include <Math.h>

Showplace::Showplace(const std::string & _name, const  std::string & _description, double a, double b)
{
	name = _name;
	description = _description;
	x = a;
	y = b;
};

std::string Showplace::GetName()
{
	return name;
};

std::string Showplace::GetDescription()
{
	return description;
};

double Showplace::GetDistance(double a, double b)
{
	return std::sqrt((x - a)*(x - a) + (y - b)*(y - b));
}