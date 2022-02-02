#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	String a("aaa");

	cout << a;
}