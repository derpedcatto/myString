#include "string.h"

/*problems?*/
// concat capacity ?
// concat int strcat_s ?
// cin.getline(text, 200) - 200 ?

/*bugs*/
// Replace (String) ensure capacity
// Replace (String) b(aa) c(a) error
// Equals ?

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
	if (length != other.length)
		return false;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != other.arr[i])
			return false;
	}

	return true;
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

	int count = 0;
	for (int i = length; i < length + other.length + 1; i++)
	{
		arr[i] = other.arr[count];
		count++;
	}

	length += other.length;
}
void String::Concat(const char* other)
{
	int charlength = strlen(other);

	if (capacity < length + charlength)
	{
		capacity += charlength;
		SetString(arr, capacity);
	}

	int count = 0;
	for (int i = length; i < length + charlength + 1; i++)
	{
		arr[i] = other[count];
		count++;
	}
	length += charlength;
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
ostream& operator << (ostream& output, const String& src)
{
	src.Print();
	return output;
}
istream& operator >>(istream& input, String& src)
{
	src.GetLine();
	return input;
}
String& String::operator=(const String& other)
{
	capacity = other.capacity;
	length = other.length;
	strcpy_s(arr, length + 1, other.arr);
	return *this;
}
String& String::operator+=(const String& other)
{
	Concat(other);
	return *this;
}
String& String::operator+=(const char* other)
{
	Concat(other);
	return *this;
}
String& String::operator()(const char* other)
{
	SetString(other, capacity);
	return *this;
}
String operator+(const String& left, const String& right)
{
	String newstring(left.capacity + right.capacity);
	newstring.length = left.length + right.length;

	for (int i = 0; i < left.length + right.length + 1; i++)
	{
		if (i < left.length)
		{
			newstring.arr[i] = left.arr[i];
		}
		else
		{
			newstring.arr[i] = right.arr[i - left.length];
		}
	}

	return newstring;
}
String operator+(const String& left, const char* right)
{
	String newstring(left.capacity + strlen(right));
	newstring.length = left.length + strlen(right);

	for (int i = 0; i < left.length + strlen(right) + 1; i++)
	{
		if (i < left.length)
		{
			newstring.arr[i] = left.arr[i];
		}
		else
		{
			newstring.arr[i] = right[i - left.length];
		}
	}

	return newstring;
}
String operator+(const char* left, const String& right)
{
	String newstring(strlen(left) + right.capacity);
	newstring.length = strlen(left) + right.length;

	for (int i = 0; i < strlen(left) + right.length + 1; i++)
	{
		if (i < strlen(left))
		{
			newstring.arr[i] = left[i];
		}
		else
		{
			newstring.arr[i] = right.arr[i - strlen(left)];
		}
	}

	return newstring;
}
String operator+(const String& left, const char right)
{
	String newstring(left.capacity + 1);
	newstring.length = left.length + 1;

	for (int i = 0; i < left.length; i++)
	{
		newstring.arr[i] = left.arr[i];
	}

	newstring.arr[left.length] = right;
	newstring.arr[left.length + 1] = '\0';
	return newstring;
}
String operator+(const char left, const String& right)
{
	String newstring(right.capacity + 1);
	newstring.length = right.length + 1;

	newstring.arr[0] = left;
	for (int i = 0; i < right.length + 1; i++)
	{
		newstring.arr[i + 1] = right.arr[i];
	}
	return newstring;
}
char String::operator[](int index)
{
	if (index < length)
		return arr[index];
	else
		return -1;
}
bool String::operator==(const String& other)
{
	return Equals(other);
}
bool String::operator!=(const String& other)
{
	return !(Equals(other));
}
bool String::operator<(const String& other)
{
	return length > other.length;
}
bool String::operator>(const String& other)
{
	return length < other.length;
}
bool String::operator>=(const String& other)
{
	return length >= other.length;
}
bool String::operator<=(const String& other)
{
	return length <= other.length;
}
String::operator char* ()
{
	return arr;
}
String::operator int()
{
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 48 || arr[i] > 57)
			return -1;

		result += (arr[i] - '0');
		result *= 10;
	}

	return result /= 10;
}
String::operator double()
{
	double result = 0;
	int i = 0;
	int count = 0;
	bool isCount = false;
	for (;i < length; i++)
	{
		if (arr[i] == 46 && isCount == true)
			return -1;

		if (arr[i] == 46 && isCount == false)
		{
			isCount = true;
			continue;
		}


		if (arr[i] < 48 || arr[i] > 57)
			return -1;

		result += (arr[i] - '0');
		result *= 10;

		if (isCount)
			count++;
	}

	result /= 10;

	for (int j = 0; j < count; j++)
		result *= 0.1;


	return result;
}

/*Dest-Get*/
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