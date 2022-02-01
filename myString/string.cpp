#include "string.h"
#include <iostream>
using namespace std;

/*problems?*/
// concat capacity ?
// concat int strcat_s ?
// cin.getline(text, 200) - 200 ?

/*bugs*/
// Replace (String) ensure capacity
// Replace (String) b(aa) c(a) error

/*
- Split
- Concat (double)
*/

/*Methods*/
const void String::Print() const
{
	cout << GetCharArray();
}
const void String::PrintLn() const
{
	Print();
	cout << "\n";
}
const char String::GetCharAt(unsigned int index) const
{
	if (index > 0 || index < length + 1)
		return arr[index];
	else
		return -1;
}
const char* String::GetCharArray() const
{
	return arr;
}
const bool String::Contains(const String& other)
{
	if (strstr(arr, other.arr) != NULL)
		return true;
	else
		return false;
}
const bool String::EndsWith(const String& other)
{
	int j = 0;
	for (int i = length - other.length; i < length; i++)
	{
		if (arr[i] != other.arr[j])
			return false;
		j++;
	}
	return true;
}
const bool String::StartsWith(const String& other)
{
	for (int i = 0; i < other.length; i++)
	{
		if (arr[i] != other.arr[i])
			return false;
	}
	return true;
}
const bool String::Equals(const String& other)
{
	if (strcmp(arr, other.arr) < 0)
		return false;
	else
		return true;
}

void String::Clear()
{
	arr[0] = '\0';
	length = 0;
}
void String::GetLine()
{
	char* text = new char;
	cin.getline(text, 200);
	
	SetString(text, capacity);
}
void String::Concat(const String& other)
{
	if (capacity < length + other.length)
	{
		capacity += other.capacity;
		SetString(arr, capacity);
	}

	length += other.length;

	int count = 0;
	for (int i = length - other.length; i < length; i++)
	{
		arr[i] = other.arr[count];
		count++;
	}
}
void String::Concat(const char* other)
{
	int charlength = strlen(other);

	if (capacity < length + charlength)
	{
		capacity += charlength;
		SetString(arr, capacity);
	}

	length += charlength;

	int count = 0;
	for (int i = length - charlength; i < length; i++)
	{
		arr[i] = arr[count];
		count++;
	}
}
void String::Concat(int other)
{
	int intlength = 0;
	int tmp = other;
	while (true)
	{
		intlength++;
		tmp /= 10;
		if (tmp <= 0)
			break;
	}

	length += intlength;

	intlength++;
	char* tmparray = new char[intlength];

	sprintf_s(tmparray, intlength, "%d", other);

	if (capacity < length + intlength)
	{
		capacity += intlength;
		SetString(arr, capacity);
	}

	strcat_s(arr, capacity, tmparray);

	delete[] tmparray;
}
void String::Concat(double other)
{

}
void String::Remove(int index)
{
	length -= index;
	arr[length] = '\0';
}
void String::Remove(int start, int count)
{
	if (count > ((int)length - count))
		length = start - 1;
	else
		length -= count;

	for (int i = start - 1; i < length; i++)
	{
		if (i <= length)
			arr[i] = arr[i + count];
	}
}
void String::Replace(char R, char Z)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == R)
			arr[i] = Z;
	}
}
void String::Replace(String& dest, String& src)	//find_what, replace_with
{
	char* final_arr = arr;
	while (true)
	{
		char* destfound = strstr(final_arr, dest.arr);

		if (destfound)
		{
			length += (src.length - dest.length);

			char* tmp_arr = new char[length + 1];

			int index = destfound - final_arr;

			strncpy_s(tmp_arr, length + 1, final_arr, index);					// копируем в результат начало оригинального текста по индекс замены
			strcat_s(tmp_arr, length + 1, src.arr);								// добавляем к результату заменяемое слово
			strcat_s(tmp_arr, length + 1, final_arr + index + dest.length);		// добавляем к результату остаток оригинала, без заменённого слова

			final_arr = tmp_arr;
		}
		else
		{
			delete[] arr;
			delete[] destfound;

			arr = final_arr;
			return;
		}
	}
}
void String::TrimEnd()
{
	for (int i = length - 1; i > 0; i--)
	{
		if (arr[i] != ' ')
		{
			arr[i + 1] = '\0';
			break;
		}
		length--;
	}
}
void String::TrimStart()
{
	int spacelen = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] != ' ')
			break;

		spacelen++;
	}

	length -= spacelen;
	for (int i = 0; i < length; i++)
	{
		arr[i] = arr[i + spacelen];
	}
}
void String::Trim()
{
	TrimStart();
	TrimEnd();
}
void String::Reverse()
{
	int count = length - 1;
	for (int i = 0; i < length / 2; i++)
	{
		swap(arr[i], arr[count]);
		count--;
	}
}
void String::SortAZ()
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
void String::SortZA()
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		for (int j = 0; arr[j] != '\0'; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}
void String::Shuffle()
{
	for (int i = 0; i < length; i++)
	{
		swap(arr[i], arr[rand() % length]);
	}
}
void String::RandomFill()
{
	String tmp("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = tmp.arr[rand() % tmp.length];
	}
}

int String::CompareTo(String other)
{
	if (strlen(arr) < strlen(other.arr))
		return -1;
	else if (strlen(arr) > strlen(other.arr))
		return 1;
	else
		return 0;
}
int String::CompareTo(char* other)
{
	if (strlen(arr) < strlen(other))
		return -1;
	else if (strlen(arr) > strlen(other))
		return 1;
	else
		return 0;
}

int String::IndexOf(char& src)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == src)
			return i;
	}
	return -1;
}
int String::IndexOf(String& src)
{
	for (int i = 0; i < length - src.length; i++)
	{
		int index = 0;
		int count = 0;
		for (int j = i; index < src.length; j++)
		{
			if (arr[j] == src.arr[index])
				count++;
			index++;
		}

		if (count == src.length)
			return i;
	}
	return -1;
}
int String::LastIndexOf(char& src)
{
	for (int i = length - 1; i > 0; i--)
	{
		if (arr[i] == src)
			return i;
	}
	return -1;
}
int String::LastIndexOf(String& src)
{
	for (int i = length - 1; i >= src.length; i--)
	{
		int index = src.length - 1;
		int count = 0;
		for (int j = i; index >= 0; j--)
		{
			if (arr[j] == src.arr[index])
				count++;
			index--;
		}

		if (count == src.length)
			return i - (src.length - 1);
	}
	return -1;
}

String String::ToUpper()
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] -= 32;
		}
		if (arr[i] >= 'а' && arr[i] <= 'я')
		{
			arr[i] -= 32;
		}
	}
	return *this;
}
String String::ToLower()
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			arr[i] += 32;
		}
		if (arr[i] >= 'А' && arr[i] <= 'Я')
		{
			arr[i] += 32;
		}
	}
	return *this;
}
String* String::Split(char separator, int& pieces)
{
	pieces = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == separator)
			pieces++;

	int* arrindex = new int[pieces];
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == separator)
		{
			arrindex[count] = i;
			count++;
		}
	}

	String* result = new String[pieces];
	for (int i = 0; i < pieces; i++)
	{

	}

	delete[] arrindex;
	return &result[pieces];
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

void String::SetString(const char* arr, unsigned int capacity)
{
	length = strlen(arr);
	while (true)
	{
		if (length >= capacity)
		{
			delete[] this->arr;
			capacity = length * 1.5;
			this->arr = new char[capacity];
		}
		else
			break;
	}
	strcpy_s(this->arr, length + 1, arr);
}