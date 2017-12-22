#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

template <class T>;
namespace lab1
{
	class IniParser
	{
	public:
		IniParser();
		void initializator();
		void readfile(const std::string &filename);
		void ShowNeed(const std::string &section, const std::string &name);
	private:
		void deleteother();
		void needview();
		std::vector <std::string> _rawlines, _readylines, _notreadylines;
		std::string _rawline, _section;
		std::map < std::string, std::string> _pairsofinformation;
	
	};
}