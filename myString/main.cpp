#include <iostream>
#include "string.h"
using namespace std;

int main()
{
	String a("123");
	a.Print();

	cout << a.GetCharAt(1);
}