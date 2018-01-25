
#include "Mytrie.h"


typedef std::pair<KeyType, int > pair;
//ori lerman is a bitch.
int main()
{
	std::vector<pair> vec;
	pair temp;
	temp.second = 1;
	bool exists;
	bool word = false;
	char ch = '/';

	//ch = getchar();

	ch = getchar();
	while (ch != '.')
	{
		word = false;
		temp.first.clear();
		exists = false;

		if (ch == ' ' || ch=='\n')
		{
			ch = getchar();
		}
		else if (ch == '.')
			break;
		else
		{
			while (ch != ' ' && ch != '.'&&ch!='\n')
			{

				temp.first.push_back(ch);
				ch = getchar();

			}
			word = true;

		}
		if (word)
		{

			for (pair& t : vec)
				if (t.first.compare(temp.first) == 0)
				{
					t.second++;
					exists = true;
				}
			if (!exists)
			{
				vec.push_back(temp);
			}

		}


	}


	Mytrie m;

	while (vec.size() != 0)
	{
		temp = vec[vec.size() - 1];
		vec.pop_back();
		m.insert(temp.first, temp.second);
	}

	ch = '/';//initialization between stages
	temp.first.clear();
	temp.second = 0;
	std::cin.clear();
	std::string dummy;
	std::getline(std::cin, dummy, '\n');
	ch = getchar();

	while (ch != '.')//second stage
	{
		word = false;
		temp.first.clear();

		if (ch == ' ' || ch == '\n')
		{
			ch = getchar();
		}
		else if (ch == '.')
			break;
		else
		{
			while (ch != ' ' && ch != '.'&&ch != '\n')
			{

				temp.first.push_back(ch);
				ch = getchar();

			}
			word = true;

		}
		if (word)
		{
			int apperences = m.find(temp.first);
			if (apperences != 0)
			{
				std::cout << apperences << std::endl;
				m.Delete(temp.first);
			}
			else
				std::cout << "did you mean " << m.approxFind(temp.first)<<"?" << std::endl;
			
		}
	}

	


	return 1;

};

