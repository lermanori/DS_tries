#include "Mytrie.h"
#include <iostream>

void Mytrie::makeEmpty()
{
	root = new node;
	root->setWord("root");
}
Data Mytrie::find(KeyType key)
{
	node* curr = root;
	bool found = false;
	size_t i = 0;
		
	while (curr->data[curr->asciToNum(key[i])] != nullptr&&i<key.size())
	{
			curr = curr->data[curr->asciToNum(key[i])];
			i++;

	}
	if (key.compare(curr->getWord()) == 0)
		return curr->getNumOfData();
	else
		return Data(0);

}
void Mytrie::Delete(KeyType key)
{
	size_t num = find(key);

	node* curr = root;
	node* holder = nullptr;

	size_t i = 0;
	if (num == 0)
		std::cout << "dont fuck with me";//supose to throw exeption "incorrect input of values"
	else
	{
		std::stack<node*> st;
		while (i < key.size()&&curr->data[curr->asciToNum(key[i])] != nullptr)
		{
			st.push(curr->data[curr->asciToNum(key[i])]);
			curr = curr->data[curr->asciToNum(key[i])];
			i++;
		}
		node* tster = st.top();
		while (key.compare(tster->getWord()) != 0)
		{
			st.pop();
			tster = st.top();
		}
		if (tster->getTakenSpots() != 0)
			tster->setWord(key[key.size() - 1]);
		else
			while(tster->getNumOfData()==0)
			{
			delete tster;
			}

	}

}
void Mytrie::insert(KeyType key, Data data)
{
	node* holder = root;
	node* curr = root;
	bool found = false;
	size_t i = 0;
	while ((i < key.size()) && found == false)
	{

		if (curr->data[curr->asciToNum(key[i])] != nullptr)//continues exists
		{
			holder = curr;
			curr = curr->data[curr->asciToNum(key[i])];
			i++;
		}
		else// nullptr->continue doesnt exists
		{
			if (key.compare(curr->getWord()) == 0)
			{
				curr->setNumOfData(curr->getNumOfData() + 1);
				found = true;
			}
			else if (curr->getWord()[i] == key[i])
			{

				curr->data[curr->asciToNum(curr->getWord()[i])] = new node(curr->getWord(), curr->getNumOfData());
				curr->setWord(curr->getWord()[i - 1]);
				curr->setNumOfData(curr->getNumOfData() - 1);
				curr->setTakenSpots(curr->getTakenSpots() + 1);
				holder = curr;
				curr = curr->data[curr->asciToNum(key[i])];
				i++;

			}
			else
			{
				if (curr->getNumOfData() != 0 && curr->getTakenSpots() != 0)
				{
					int num = 1;
					curr->data[curr->asciToNum(key[i])] = new node(key, data);

					curr->data[curr->asciToNum(curr->getWord()[i])] = new node(*curr);
					curr->setWord(curr->getWord()[i - 1]);
					curr->setNumOfData(curr->getNumOfData() - 1);
					curr->setTakenSpots(curr->getTakenSpots() + 2);
				}
				else
				{
					curr->setTakenSpots(curr->getTakenSpots() + 1);
					curr->data[curr->asciToNum(key[i])] = new node(key, data);

				}

				found = true;
			}




		}
	}
}
bool Mytrie::isEmpty()
{
	return root == nullptr ? bool(true) : bool(false);
}
Mytrie::Mytrie() :root(nullptr)
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
