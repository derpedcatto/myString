#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	String a("1.112");
	String b("aaaaaa");

	//char* c = new char[4] { '2', '2', '3'};
	//char* c = new char[3] { '2', '2' };
	//char* c = new char[5] { '2', '2', '2', '2' };

	double d = (double)a;

	cout << d;
	cout << endl;
	//a.Print();
}