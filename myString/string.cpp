#include "string.h"
#include <iostream>
using namespace std;

/*Methods*/
const void String::Print() const
{
	for (int i = 0; i < length; i++)
		cout << arr[i];
}
const void String::PrintLn() const
{
	Print();
	cout << "\n";
}
const char String::GetCharAt(unsigned int index) const
{
	return arr[index];
}

/*Operators*/


/*Dest-Get-Set*/
String::~String()
{
	if (arr != nullptr) delete arr;
}

const char* String::GetString() const
{
	return arr;
}
const int String::GetLength() const
{
	return length;
}
const int String::GetCapacity() const
{
	return capacity;
}

void String::SetString(const char* str, unsigned int capacity)
{
	length = strlen(str);
	if (length >= capacity)
	{
		delete[] this->arr;
		capacity = length + 20;
		this->arr = new char[capacity];
	}
	strcpy_s(this->arr, length + 1, str);
}