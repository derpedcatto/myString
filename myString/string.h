#pragma once
class String
{
private:
	char* arr;
	unsigned int length;
	unsigned int capacity = 80;

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

	/*Operators*/

	/*Dest-Set-Get*/
	~String();

	const char* GetString() const;
	const int GetLength() const;
	const int GetCapacity() const;

	void SetString(const char* arr, unsigned int capacity);
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