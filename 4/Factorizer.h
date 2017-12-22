#pragma once
#include <vector>
#include <stdint.h>

class Factorizer
{
public:
	Factorizer(uint64_t num);
	std::string Out();
private:
	void Clean();
	std::vector<uint64_t> row;
};