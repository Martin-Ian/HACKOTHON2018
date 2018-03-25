#pragma once
#include <string>
#include <iostream>

using namespace std;

class Book
{
private:
	string _firstLine;
	float _secondLine;
	string _thirdLine;
	int _year;

	string _name;
	string _author;
	string _subject;

public:

	Book()
	{
		_name = "Unknown";
		_author = "Unknown";
		_firstLine = "Unknown";
		_secondLine = -1;
		_thirdLine = "Unknown";
		_year = -1;
	}

	Book(string first, float second, string third, int last)
	{
		_name = "Unknown";
		_author = "Unknown";
		_firstLine = first;
		_secondLine = second;
		_thirdLine = third;
		_year = last;
	}

	Book(string name, string author, string first, float second, string third, int last)
	{
		_name = name;
		_author = author;
		_firstLine = first;
		_secondLine = second;
		_thirdLine = third;
		_year = last;
	}

	void setFirstLine(string data)
	{
		_firstLine = data;
	}

	string getFirstLine()
	{
		return _firstLine;
	}

	void setSecondLine(float data)
	{
		_secondLine = data;
	}

	float getSecondLine()
	{
		return _secondLine;
	}

	void setThirdLine(string data)
	{
		_thirdLine = data;
	}

	string getThirdLine()
	{
		return _thirdLine;
	}

	void setYear(int data)
	{
		_year = data;
	}

	int getYear()
	{
		return _year;
	}

	void setName(string name)
	{
		_name = name;
	}

	string getName()
	{
		return _name;
	}

	void setAuthor(string author)
	{
		_author = author;
	}

	string getAuthor()
	{
		return _author;
	}

	void setSubject(string subject)
	{
		_subject = subject;
	}

	string getSubject()
	{
		return _subject;
	}

	void displayInfo()
	{
		cout << endl;
		cout << "Title: " << _name << endl;
		cout << "Author: " << _author << endl;
		cout << "Subject: " << _subject << endl;
		cout << _firstLine << endl;
		cout << _secondLine << endl;
		cout << _thirdLine << endl;
		cout << _year << endl << endl;
	}

	void displayInfo(ostream &output)
	{
		output << "Title: " << _name << endl;
		output << "Author: " << _author << endl;
		output << "Subject: " << _subject << endl;
		output << _firstLine << endl;
		output << _secondLine << endl;
		output << _thirdLine << endl;
		output << _year << endl << endl;
	}
};