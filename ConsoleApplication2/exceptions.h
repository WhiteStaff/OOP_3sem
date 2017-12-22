#pragma once
#include <exception>
#include <string>

class FileNameError : public std::exception
{
public:
	FileNameError(std::string message);
};

class SectionNameError : public std::exception
{
public:
	SectionNameError(std::string message);
};