#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "methods.h"

using namespace std;
using namespace lab1;

int main()
{
	IniParser example;
	string filename, section, name;
	cout << "Enter file's name" << endl;
	cin >> filename;
	try
	{
		example.readfile(filename);
		example.initializator();
		cout << "Enter section " << endl;
		cin >> section;
		cout << "Enter name" << endl;
		cin >> name;
		example.ShowNeed(section, name);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	
}
