#include "Mytrie.h"


//func is for tranforming charecters to thier appropriate index places
int Mytrie::node::asciToNum(char& asci)
{
	asci = tolower(asci);
	return asci - 'a';

}
void Mytrie::node::setTakenSpots(int newTakenSpots)
{
	takenSpots = newTakenSpots;
}
void Mytrie::node::setNumOfData(int newNumOfData)
{
	numOfData = newNumOfData;
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

Mytrie::node::node()//the ctor of node is initializes the arr and vars
{
	for (size_t i = 0; i < alphaSize; i++)
		data[i] = nullptr;
	setNumOfData(0);
	setWord("\0");
	setTakenSpots(0);

}
//overload with data and key
Mytrie::node::node(KeyType key, Data data)
{
	for (size_t i = 0; i < alphaSize; i++)
		this->data[i] = nullptr;
	setNumOfData(data);
	setWord(key);
	setTakenSpots(0);
}
//destructor
Mytrie::node::~node()
{
	for (size_t i = 0; i < alphaSize; i++)
		data[i] = nullptr;
	setNumOfData(0);
	setWord("\0");
	setTakenSpots(0);

}

void Mytrie::makeEmpty()
{
	root = new node;
	root->setWord("root");
}
bool Mytrie::isEmpty()
{
	return root == nullptr ? bool(true) : bool(false);
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
			else if (curr->getWord()[i] == key[i])//same prefix
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
				if (curr->getNumOfData() != 0)//the curr is a word
				{
					int num = 1;
					curr->data[curr->asciToNum(key[i])] = new node(key, data);

					curr->data[curr->asciToNum(curr->getWord()[i])] = new node(*curr);
					curr->setWord(curr->getWord()[i - 1]);
					curr->setNumOfData(curr->getNumOfData() - 1);
					curr->setTakenSpots(curr->getTakenSpots() + 2);
				}
				else//its not a word
				{
					curr->setTakenSpots(curr->getTakenSpots() + 1);
					curr->data[curr->asciToNum(key[i])] = new node(key, data);

				}

				found = true;
			}




		}
	}
}

void Mytrie::Delete(KeyType key)
{
	size_t num = this->find(key);

	node* curr = root;
	node* holder = nullptr;

	size_t i = 0;
	if (num == 0)//word doesnt exists
		std::cout << "dont fuck with me" << std::endl;//supose to throw exeption "incorrect input of values"or" the data you enterd doesnt exists
	else if (num == 1)//word exists once
	{
		while (curr->data[curr->asciToNum(key[i])] != nullptr&&i < key.size())//finds the word
		{
			curr = curr->data[curr->asciToNum(key[i])];
			i++;

		}
		if (curr->getTakenSpots() != 0)//the word has kids
		{
			size_t j = 0;
			node* parent = root;
			while (parent->data[parent->asciToNum(key[j])] != curr &&j < key.size())//last thing i did thought that the parent of curr should be connected directly to the kid of curr
			{
				parent = parent->data[parent->asciToNum(key[j])];
				j++;
			}
			if (key.compare(curr->getWord()) == 0 && curr->getTakenSpots() == 1)//the word has one kid
			{
				for (auto* temp : curr->data)//method for finding the kid
					if (temp != nullptr)
					{
						node* holder = curr;
						parent->data[parent->asciToNum(key[j])] = temp;
						delete holder;
						break;
					}
			}
			else//the word has more than one kid
			{

				curr->setWord(curr->getWord()[i]);
				curr->setNumOfData(0);
			}


		}
		else//the word has no kids
		{
			size_t j = 0;
			node* parent = root;
			while (parent->data[parent->asciToNum(key[j])] != curr &&i < key.size())//find the parent node
			{
				parent = parent->data[parent->asciToNum(key[j])];
				j++;
			}
			parent->data[parent->asciToNum(curr->getWord()[j])] = nullptr;
			parent->setTakenSpots(parent->getTakenSpots() - 1);
			delete curr;

		}
	}
	else//word exists more than once
	{
		while (curr->data[curr->asciToNum(key[i])] != nullptr&&i < key.size())
		{
			curr = curr->data[curr->asciToNum(key[i])];
			i++;

		}
		curr->setNumOfData(curr->getNumOfData() - 1);
	}

}
KeyType  Mytrie::approxFind(KeyType  key)
{
	int i = find(key);//approx find depands on how many times the word appered
	if (i != 0)//if the word exists we return the word
		return this->find_key(key);//private func for this instance only
	else//the word doesnt exists
	{
		node* curr= root;
		while (curr->data[curr->asciToNum(key[i])] != nullptr&& i < key.size())//traverse the tree with the key while u can
		{
			curr = curr->data[curr->asciToNum(key[i])];
			i++;

		}
		if (curr->getTakenSpots() == 0)
			return curr->getWord();
		else//the place we landed isnt a word
		{
			while (curr->getNumOfData() == 0)//the place we are isnt a word
			{

			for (auto* temp : curr->data)//method for finding the first child who is a word
				if (temp != nullptr)
				{
					node* holder = curr;
					curr = temp;
					break;
				}
			}
			if (curr->getNumOfData() != 0)
				return curr->getWord();
		}

	}
}
Data Mytrie::find(KeyType key)
{
	for (auto& c : key)//tranforms every charecter into the low representation
	{
		c = tolower(c);
	}
	node* curr = root;
	bool found = false;
	size_t i = 0;

	while (curr->data[curr->asciToNum(key[i])] != nullptr&&i < key.size())//traverse the tree with the word as long as u can
	{
		curr = curr->data[curr->asciToNum(key[i])];
		i++;

	}

	if (key.compare(curr->getWord()) == 0)//if its the word
		return curr->getNumOfData();
	else//not the word
		return Data(0);

}


Mytrie::Mytrie() :root(nullptr)
{
	makeEmpty();
}
Mytrie::~Mytrie()
{
	node* curr = root;
	this->destructorRec(curr);
	delete curr;
	root = nullptr;



}
//a recursive destructor 
void Mytrie::destructorRec(node* curr)
{
	if (curr->getTakenSpots() == 0)//stop condition
	{ 
		node* holder = curr;
		delete holder;
	}
	else
	{
		for ( int i=0;i<alphaSize;i++)
			if (curr->data[i] != nullptr)
			{
				destructorRec(curr->data[i]);//delete the sub tree
				curr->data[i] = nullptr;//mark the subtree as null
				curr->setTakenSpots(curr->getTakenSpots() - 1);//sets the ts -1
			}

	}


}
//private function that is used in one instance in approx find identical to find but i would not give such power to the user and therefore its private
KeyType&  Mytrie::find_key(KeyType key)
{
	for (auto& c : key)
	{
		c = tolower(c);
	}
	node* curr = root;
	bool found = false;
	size_t i = 0;

	while (curr->data[curr->asciToNum(key[i])] != nullptr&&i < key.size())
	{
		curr = curr->data[curr->asciToNum(key[i])];
		i++;

	}

	if (key.compare(curr->getWord()) == 0)
		return curr->getWord();
	

}










