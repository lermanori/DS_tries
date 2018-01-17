#pragma once

#include <string>
#include <stack>
typedef int Data;
typedef std::string KeyType;
const int alphaSize = 26;



class Mytrie
{
	class node
	{
		KeyType word;
		int numOfData;
		int takenSpots;
	public:
		node* data[alphaSize];

		int asciToNum(char & asci);
		std::string& getWord() { return word; };
		int getNumOfData() { return numOfData; };
		int getTakenSpots() { return takenSpots; }

		void setTakenSpots(int newTakenSpots);
		void setNumOfData(int newNumOfData);
		void setWord(KeyType key);
		void setWord(char key);
		
		node();
		node(KeyType key, Data data);
		
	protected:


	};

	node* root;

public:
	void makeEmpty();
	bool isEmpty();
	Mytrie();
	~Mytrie();
	void insert(KeyType key, Data data);
	Data find(KeyType key);
	void Delete(KeyType key);

};