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
	i = m.find("ori");
	

	i = m.find("orix");
	std::cout << "orix bf deltet:"<< i << std::endl;
	m.Delete("oriX");
	std::cout << "orix after deltet:" << i << std::endl;
	
	i = m.find("alp");
	std::cout << "alp bf deltet:" << i << std::endl;
	m.Delete("ALP");
	std::cout << "alp after deltet:" << i << std::endl;

	i = m.find("alp");
	std::cout << "alp bf 2 deltet:" << i << std::endl;
	m.Delete("ALP");
	std::cout << "alp after 2 deltet:" << i << std::endl;

};
