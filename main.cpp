#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <istream>
#include <fstream>
#include "Book.h"
#include <unordered_map>
#include "TrieNode.h"
#include "TrieTree.h"

using namespace std;

Book* randomInfoGenerator();

int main(void)
{
	TrieTree* theTree = new TrieTree();
	ofstream output_file;

	for (int i = 0; i < 5000; i++)
	{
		Book* newBook = randomInfoGenerator();
		newBook->setName(to_string(i));
		newBook->setAuthor(to_string(i % 11));
		newBook->setSubject(newBook->getFirstLine());
		theTree->addBook(newBook);
	}

	string cont;

	do {
		cout << endl << "Enter a book name! (0-4999)" << endl << "--> ";
		string responce;
		getline(cin, responce);
		Book* temp = theTree->getBook(responce);
		if (temp == nullptr)
		{
			cout << endl << "Book not found." << endl << endl;
		}
		else
		{
			temp->displayInfo();
			cout << "CODE FOR WEBSITE: " << temp->getSubject() << endl << endl;
		}

		cout << "Find another book? (\'y\', \'n\')" << endl << "--> ";
		getline(cin, cont);

	} while (cont.at(0) == 'y');

	cout << "Goodbye!" << endl;

	/*
	output_file.open("Lib_Data.txt", ios::out);
	for (int i = 0; i < 5000; i++)
	{
		theTree->getBook(to_string(i))->displayInfo(output_file);
	}
	output_file.close();
	*/
	

	return 0;
}

Book* randomInfoGenerator()
{
	time_t t = time(0);

	Book* book = new Book();
	long random_number = rand();
	long random_number_2 = rand();
	long random_number_3 = rand();

	//number 97-122 is a-z
	//first value
	char first_letter = random_number % 27;
	char second_letter = random_number_2 % 27;
	string first_line;

	first_letter += 96;
	second_letter += 96;

	first_line.push_back(first_letter);
	first_line.push_back(second_letter);

	//second value
	int second_line_num = random_number % 10000 + 999;

	//third value
	//decimal-letter-number
	char cutter_letter = random_number_3 % 27;
	cutter_letter += 96;

	int third_line_num = random_number % 100;

	string third_line;
	third_line.push_back('.');
	third_line.push_back(cutter_letter);
	third_line.append(to_string(third_line_num));

	//fourth value
	int year = rand() % 150 + 1900;

	int cases = rand() % 6;
	switch (cases)
	{
	case 0:
		book->setFirstLine("AC");
		break;
	case 1:
		book->setFirstLine("BL");
		break;
	case 2:
		book->setFirstLine("DS");
		break;
	case 3:
		book->setFirstLine("HA");
		break;
	case 4:
		book->setFirstLine("HG");
		break;
	case 5:
		book->setFirstLine("NX");
		break;
	}

	book->setSecondLine(second_line_num);
	book->setThirdLine(third_line);
	book->setYear(year);

	return book;
}