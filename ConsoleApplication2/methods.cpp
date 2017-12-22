#include "methods.h"
#include "exceptions.h"

namespace lab1
{

	void IniParser::readfile(const std::string &filename)
	{
		std::ifstream fin(filename);
		if (fin.is_open() == false)
		{
			throw FileNameError("Can't open this file");
		}
		while (!fin.eof())
		{
			getline(fin, _rawline);
			_rawlines.push_back(_rawline);
		}
	}

	void IniParser::deleteother()
	{
		int size = _rawlines.size();
		for (int i = 0; i < size; i++)
		{
			_notreadylines.push_back("");
			bool flag = 0;
			for (auto q : _rawlines[i])
			{
				if (q == ';') (flag = 1);
				if ((q != ' ') && (flag == 0))
				{
					_notreadylines[i].push_back(q);
				}
			}
			
			//if (i < size) { _readylines.push_back(""); }
		}
		for (auto q : _notreadylines)
		{
			if (q != "")
			{
				_readylines.push_back(q);
			}
		}
	}

	void IniParser::needview()
	{
		std::pair< std::string, std::string> needpair;
		std::string firstpart, secondpart;
		int size = _readylines.size();
		for (int i = 0; i < size; i++)
		{
			if (_readylines[i][0] == '[')
			{
				_readylines[i].erase(0, 1);
				_readylines[i].pop_back();
				_section = _readylines[i];
			}
			else
			{
				bool flag = false;
				firstpart = _section + ' ';
				for (auto q : _readylines[i])		
				{
					if (q == '=')
					{
						flag = true;
					}
					if ((flag == false) && (q != '='))
					{
						firstpart.push_back(q);
					}
					else if ((flag == true) && (q != '='))
					{
						secondpart.push_back(q);
					}
				}
				needpair.first = firstpart; needpair.second = secondpart;
				_pairsofinformation.insert(needpair);
				firstpart.clear();
				secondpart.clear();
			}

		}
	}

	void IniParser::initializator()
	{
		deleteother();
		needview();
	}

	void IniParser::ShowNeed(const std::string &section, const std::string &name)
	{
		std::string all;
		all = section + ' ' + name;
		if (_pairsofinformation.find(all) == _pairsofinformation.end())
		{
			throw SectionNameError("Incorrect combination of section and parameter");
		}
		std::cout << _pairsofinformation[all] << std::endl;
	}

	IniParser::IniParser() {}
}