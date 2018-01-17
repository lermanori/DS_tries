#include "Mytrie.h"
 #include <iostream>

void main() 
{
	Mytrie m;
	m.insert("ori", 1);
	m.insert("ob", 1);
	m.insert("oriX", 1);
	m.insert("orly", 1);
	m.insert("alp", 2);
	m.insert("ox", 1);
	int i = m.find("ori");
	std::cout <<"ori:"<< i<<std::endl;
	 i = m.find("ob");
	std::cout << "ob:" << i << std::endl;
	 i = m.find("orix");
	std::cout << "orix:" << i << std::endl;
	 i = m.find("alp");
	std::cout << "alp:" << i << std::endl;
	 i = m.find("oril");
	std::cout << "oril:" << i << std::endl;
	m.Delete("ori");
	m.Delete("oriX");
	i = m.find("ori");
	std::cout << "ori after deltet:"<< i << std::endl;

};
