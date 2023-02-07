#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


class MyString
{

private:

	char* str;
	int length;

public:

	MyString();

	MyString(const char* _str);

	MyString(const char* _str, int length);

	MyString& operator =(const MyString& obj);

	MyString(const MyString& obj);

	MyString operator +(const MyString& obj);

	void Set();

	void Print();

	bool MyStrStr(const char* _strf);

	int  MyChr(char c);

	int MyStrLen();

	void MyDelChr(char c);

	int MyStrCmp(MyString& b);

	~MyString();
};


MyString::MyString()
{
	str = nullptr;
}


MyString::MyString(const char* _str)
{
	str = new char[80 + 1];

	strcpy(str, _str);
}

MyString::MyString(const char* _str, int length)
{

	str = new char[length];

	strcpy(str, _str);
}

MyString& MyString::operator=(const MyString& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}

	int length = strlen(obj.str);
	str = new char[length + 1];

	strcpy(str, obj.str);

	return *this;
}

MyString::MyString(const MyString& obj)
{
	int length = strlen(obj.str);
	str = new char[length + 1];

	strcpy(str, obj.str);
}

MyString MyString::operator+(const MyString& obj)
{
	MyString newStr;

	int length = strlen(str);
	int slength = strlen(obj.str);

	newStr.str = new char[length + slength + 1];

	int i = 0;

	for (; i < length; i++)
	{
		newStr.str[i] = str[i];
	}


	for (size_t j = 0; j < slength; j++, i++)
	{
		newStr.str[i] = obj.str[j];
	}

	newStr.str[length + slength] = '\0';

	return newStr;
}

void MyString::Set()
{
	this->str = new char[80];
	cout << "Bbedute ctroky: " << endl;

	fgets(this->str, 80, stdin);
}

void MyString::Print()
{
	
	cout << str << endl;
	
}

bool MyString::MyStrStr(const char* _strf)
{
	int length = strlen(str);
	int slength = strlen(_strf);
	int k = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < slength; j++) {
			if (str[i+j] != _strf[j]) {
				break;
			}
			else {
				k++;
			}
		}
	}
	if (k == slength) {
		return true;
	}
	return false;
}

int MyString::MyChr(char c)
{
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] == c) {
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

void MyString::MyDelChr(char c) {
	bool hasChar = false;
	int length = strlen(str);
	char* _str = new char[length - 1];

	int i = 0;
	for (i; i < length; i++) {
		_str[i] = str[i];
		if (str[i] == c) {
			hasChar = true;
			break;
		}
	}
	if (hasChar == true) {
		for (i; i < length; i++) {
			_str[i] = str[i+1];
		}
		strcpy(str, _str);
		_str = nullptr;
		cout << str << endl;
	}
	else {
		cout << "CumBol He HauDeH" << endl;
	}

}

int MyString::MyStrCmp(MyString& b) {
	int length = strlen(str);
	int slength = strlen(b.str);
	if (length > slength) {
		return 1;
	} 
	else if (length < slength) {
		return -1;
	}
	else {
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


MyString::~MyString()
{

	delete[]str;
}

int main()
{


	MyString str1("Hello");
	MyString str2("World!", 123);

	str1.Print();
	str2.Print();

	MyString str3 = str1 + str2;

	str3.Print();

	MyString str4(str3);

	str4.Print();

	MyString str5;

	str5.Set();
	str5.Print();

	cout << str3.MyStrStr("Hello") << endl;

	cout << str3.MyChr('i') << endl;

	cout << str3.MyStrLen() << endl;

	str3.MyDelChr('e');
	str3.MyDelChr('5');

	
	cout << str3.MyStrCmp(str4) << endl;
}
