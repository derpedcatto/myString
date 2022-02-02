#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	unsigned int length = 1;
	unsigned int capacity = 80;
	char* arr = new char[capacity];

public:
	/*Constructors*/
	String()
	{
		SetString("", capacity);
	}
	String(const char* arr)
	{
		SetString(arr, capacity);
	}
	explicit String(unsigned int capacity)
	{
		SetString("", capacity);
	}
	String(const String& original)
	{
		SetString(original.arr, original.capacity);
	}

	/*Methods*/
	const void Print() const;
	const void PrintLn() const;
	const char GetCharAt(unsigned int index) const;
	const char* GetCharArray() const;
	const bool Contains(const String& other);
	const bool EndsWith(const String& other);
	const bool StartsWith(const String& other);
	const bool Equals(const String& other);

	void SetString(const char* arr, unsigned int capacity);
	void Clear();
	void GetLine();
	void Concat(const String& other);
	void Concat(const char* other);
	void Concat(int other);
	void Concat(double other);
	void Remove(int index);
	void Remove(int start, int count);
	void Replace(char R, char Z);
	void Replace(String& R, String& Z);
	void TrimEnd();
	void TrimStart();
	void Trim();
	void Reverse();
	void SortAZ();
	void SortZA();
	void Shuffle();
	void RandomFill();

	int CompareTo(String other);
	int CompareTo(char* other);
	int IndexOf(char& src);
	int IndexOf(String& src);
	int LastIndexOf(char& src);
	int LastIndexOf(String& src);
	String ToUpper();
	String ToLower();
	String* Split(char separator, int& pieces);

	/*Operators*/
	friend ostream& operator<<(ostream& output, const String& src);
	friend istream& operator>>(istream& input, String& src);
	friend String operator+(const String& left, const String& right);
	friend String operator+(const String& left, const char* right);
	friend String operator+(const char* left, const String& right);
	friend String operator+(const String& left, const char right);
	friend String operator+(const char left, const String& right);
	String& operator=(const String& other);
	String& operator+=(const String& other);
	String& operator+=(const char* other);
	String& operator()(const char* other);

	char operator[](int index);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator>(const String& other);
	bool operator<(const String& other);
	bool operator>=(const String& other);
	bool operator<=(const String& other);
	operator char* ();
	operator int();
	operator double();

	/*Dest-Get*/
	~String();

	const char* GetString() const;
	const int GetLength() const;
	const int GetCapacity() const;
};

/*
	void Clear()
	{
		text[0] = '\0';
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 == capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}
*/