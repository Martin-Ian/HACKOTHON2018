#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "TrieNode.h"
#include "Book.h"

using namespace std;

class TrieTree
{
private:
	TrieNode* controler;

public:
	TrieTree()
	{
		controler = new TrieNode("CONTROLER", "CONTROLER");
	}

	TrieNode* getControler()
	{
		return controler;
	}

	//Returns an unordered map of book pointers based on a subject
	unordered_map<string, Book*> getSubject(string subjectToFind)
	{
		unordered_map<string, Book*> booksBySubject;

		TrieNode* temp = controler->getChild(subjectToFind);

		if (temp == nullptr)
		{
			return booksBySubject;
		}

		vector<TrieNode*> authors;

		for (auto A : temp->getChildren())
		{
			authors.push_back(A.second);
		}
		for (auto B : authors)
		{
			for (auto C : B->getChildren())
			{
				Book* tempBook = C.second->getBook();

				if (tempBook != nullptr)
				{
					booksBySubject[tempBook->getName()] = tempBook;
				}
			}
		}
		return booksBySubject;
	}

	Book* getBook(string name)
	{
		for (auto S : controler->getChildren())
		{
			for (auto A : S.second->getChildren())
			{
				for (auto B : A.second->getChildren())
				{
					if (B.second->getBook()->getName() == name)
					{
						return B.second->getBook();
					}
				}
			}
		}
		return nullptr;
	}

	void addBook(Book* bookToAdd)
	{
		controler->addNewBook(bookToAdd->getSubject(), bookToAdd);
	}

};