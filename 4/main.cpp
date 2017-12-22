#include "Factorizer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
	thread t;
	mutex lock;
	bool pause, good = false;
	string filename;
	condition_variable con;
	//cout << "Input filename" << endl;
	//cin >> filename;
	ifstream fin("123.txt");
	ofstream  fout("out.txt");
	t = thread ([&] {
	while ((fin.eof() == false) && (!good))
	{
		if (!pause) 
		{
			string ch;
			getline(fin, ch);
			if (ch != "")
			{
				uint64_t num = stoi(ch);
				Factorizer example(num);
				fout << example.Out() << endl;
			}
		}
		else
		{
			fout.close();
			unique_lock<mutex> pause(lock);
			con.wait(pause);
			fout.open("out.txt", ios::app);
		}
	}
	fin.close();
	fout.close;
	});
	
	t.join();
}