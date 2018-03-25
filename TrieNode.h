#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Book.h"
#include <unordered_map>

using namespace std;

class TrieNode
{
private:
	//Unordered map of TrieNodes allows for quick seaching.
	unordered_map<string, TrieNode*> _children;
	//The data is either the subject, author, or bookName, depending on usage
	string _data;
	//type is WHAT kind of node, subject vs author, vs title node
	string _type;
	//the_book will only be used by name nodes, so should be nullptr for all others
	Book* the_book = nullptr;

public:
	//Constructors
	TrieNode()
	{

	}

	TrieNode(string type, string data)
	{
		_data = data;
		_type = type;
	}

	//Allows getting/setting data
	void setData(string newData)
	{
		_data = newData;
	}

	string getData()
	{
		return _data;
	}

	//Adding a child from an existing nodeptr or from just the data
	void addChild(TrieNode* nodeToAdd)
	{
		_children[nodeToAdd->getData()] = nodeToAdd;
	}

	void addChild(string type, string newData)
	{
		TrieNode* nodeToAdd = new TrieNode(type, newData);
		_children[newData] = nodeToAdd;
	}

	//Recursively add a new book
	void addNewBook(string thingToAdd, Book* newBook)
	{
		if (_type == "CONTROLER")
		{
			if (_children[thingToAdd] == nullptr)
			{
				_children[thingToAdd] = new TrieNode("Subject", thingToAdd);
			}
			_children[thingToAdd]->addNewBook(newBook->getAuthor(), newBook);
		}
		else if (_type == "Subject")
		{
			if (_children[thingToAdd] == nullptr)
			{
				_children[thingToAdd] = new TrieNode("Author", thingToAdd);
			}
			_children[thingToAdd]->addNewBook(newBook->getName(), newBook);
		}
		else if (_type == "Author")
		{
			if (_children[thingToAdd] == nullptr)
			{
				_children[thingToAdd] = new TrieNode("Title", thingToAdd);
			}
			_children[thingToAdd]->addNewBook(newBook->getName(), newBook);
		}
		else if (_type == "Title")
		{
			setBook(newBook);
		}
	}

	//Gets a specific child
	TrieNode* getChild(string toFind)
	{
		//Check for nullptr
		if (_children[toFind] == nullptr)
		{
			return nullptr;
		}
		else
		{
			return _children[toFind];
		}
	}

	//Gets all children
	unordered_map<string, TrieNode*> getChildren()
	{
		return _children;
	}

	//Getting and setting books, for title nodes
	void setBook(Book* bookToAdd)
	{
		the_book = bookToAdd;
	}

	void setBook(string first, float second, string third, int last)
	{
		the_book = new Book(first, second, third, last);
	}

	Book* getBook()
	{
		//Only want to get the book if a node is a title node
		if (_type == "Title")
		{
			return the_book;
		}
		else
		{
			return nullptr;
		}
	}

	//Getter/setters for the type
	void setType(string type)
	{
		_type = type;
	}

	string getType()
	{
		return _type;
	}

};