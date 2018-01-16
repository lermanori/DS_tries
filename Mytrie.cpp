#include "Mytrie.h"
#include <iostream>

void Mytrie::makeEmpty()
{
	root = new node;
}
Data Mytrie::find(KeyType key)
{
	node* curr = root;
	bool found = false;
	size_t i = 0;
	while (!found && i < key.size())
	{
		if (curr->data[curr->asciToNum(key[i])]->getWord()[0] == '\0')//no leaf
			if (curr->data[curr->asciToNum(key[i])]->data != nullptr)
			{
				curr = curr->data[curr->asciToNum(key[i])];
				i++;
			}
			else// nullptr
				return Data(0);
		else//is a leaf
			return curr->data[curr->asciToNum(key[i])]->getNumOfData();
	}

}
void Mytrie::Delete(KeyType key)
{
	size_t num = find(key);

	node* curr = root;
	node* holder= nullptr;

	size_t i = 0;
	while (i < key.size())
	{

		if (curr->data[curr->asciToNum(key[i])] != nullptr)//continues exists
		{
			if (num > 1)
			{
				curr = curr->data[curr->asciToNum(key[i])];
				i++;
			}
			if (num == 1)
			{
				holder = curr;
				curr = curr->data[curr->asciToNum(key[i])];
			    holder->data[curr->asciToNum(key[i])] = nullptr;
				i++;
			
			}
		}
		else// nullptr->continue doesnt exists
		{
			//throw exeption there is no word to delete
			std::cout << "hey there is no word like this";
		}
	}
	curr->setWord("\0");//sets the key to the the last
	curr->setNumOfData(curr->getNumOfData() - 1);
	curr->setTakenSpots(curr->getTakenSpots() - 1);
}
void Mytrie::insert(KeyType key, Data data)
{
	node* holder = root;
	node* curr = root;
	bool found = false;
	size_t i = 0;
	while (i < key.size()&&!found)
	{

		if (curr->data[curr->asciToNum(key[i])] != nullptr)//continues exists
		{
			holder = curr;
			curr = curr->data[curr->asciToNum(key[i])];
			i++;
		}
		else// nullptr->continue doesnt exists
		{
			if (holder->getTakenSpots() != 0)
			{
				curr->data[curr->asciToNum(curr->getWord()[i])] = new node(curr->getWord(), curr->getNumOfData());
				curr->setTakenSpots(curr->getTakenSpots() + 1);
				curr->setNumOfData(0);
				curr->setWord(curr->getWord()[i-1]);

			}
			curr->setTakenSpots(curr->getTakenSpots() + 1);
			curr->data[curr->asciToNum(key[i])] = new node;
			curr = curr->data[curr->asciToNum(key[i])];
			i++;
			curr->setWord(key);//sets the key to the the last
			curr->setNumOfData(curr->getNumOfData() + 1);

			found = true;
		}
	}
	if(!found)
		curr->setNumOfData(curr->getNumOfData() + 1);
}
bool Mytrie::isEmpty()
{
	return root == nullptr ? bool(true) : bool(false);
}
Mytrie::Mytrie():root(nullptr)
{
	makeEmpty();
}

Mytrie::~Mytrie()
{
}

int Mytrie::node::asciToNum(char& asci)
{
	asci = tolower(asci);
	return asci - 'a';

}

void Mytrie::node::setWord(KeyType key)
{
	word = key;
}

void Mytrie::node::setWord(char key)
{
	word[0] = key;
	word[1] = '\0';
}

Mytrie::node::node()
{
	for (size_t i = 0; i < alphaSize; i++)
		data[i] = nullptr;
	setNumOfData(0);
	setWord("\0");
	setTakenSpots(0);

}

Mytrie::node::node(KeyType key, Data data)
{
	for (size_t i = 0; i < alphaSize; i++)
		this->data[i] = nullptr;
	setNumOfData(data);
	setWord(key);
	setTakenSpots(0);
}

void Mytrie::node::setTakenSpots(int newTakenSpots)
{
	takenSpots = newTakenSpots;
}

void Mytrie::node::setNumOfData(int newNumOfData)
{
	numOfData = newNumOfData;
}
