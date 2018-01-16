#include "Header.h"


void Mytrie::makeEmpty()
{
	root = new node;
}
Data Mytrie::find(KeyType key)
{
	node* curr = root;
	bool found = false;
	int i = 0;
	while (!found && i < key.size())
	{
		if (curr->data[asciToNum(key[i])]->getWord()[0] == '\0')//no leaf
			if (curr->data[asciToNum(key[i])]->data != nullptr)
			{
				curr = curr->data[asciToNum(key[i])];
				i++;
			}
			else// nullptr
				return Data(0);
		else//is a leaf
			return curr->data[asciToNum(key[i])]->getNumOFwords();
	}

}
void Mytrie::insert(KeyType key, Data data)
{
	node* curr = root;
	bool found = false;
	int i = 0;
	while (i < key.size())
	{

		if (curr->data[asciToNum(key[i])]->data != nullptr)//continues exists
		{
			curr = curr->data[asciToNum(key[i])];
			i++;
		}
		else// nullptr->continue doesnt exists
		{
			curr->data[asciToNum(key[i])] = new node;
			curr = curr->data[asciToNum(key[i])];
			i++;
		}
	}
	curr->setWord(key);
}
bool Mytrie::isEmpty()
{
	return root == nullptr ? bool(true) : bool(false);
}
Mytrie::Mytrie()
{
	makeEmpty();
}

Mytrie::~Mytrie()
{
}

int node::asciToNum(char& asci)
{
	asci = tolower(asci);
	return asci - 'a';

}
