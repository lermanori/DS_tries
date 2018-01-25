
#include <string>
#include <stack>
#include <vector>
#include <iostream>

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
		~node();
		node(KeyType key, Data data);
		
	};


	void destructorRec(node* curr);
	node* root;
	KeyType& find_key(KeyType key);


public:

	void makeEmpty();
	bool isEmpty();
	void insert(KeyType key, Data data);
	

	Data find(KeyType key);
	void Delete(KeyType key);
	KeyType approxFind(KeyType key);


	Mytrie();
	~Mytrie();


};
