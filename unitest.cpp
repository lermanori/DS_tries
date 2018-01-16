#include "Mytrie.h"
 #include <iostream>

void main() 
{
	Mytrie m;
	m.insert("ori", 1);
	m.insert("ob", 1);
	m.insert("oriX", 1);
	int i = m.find("ori");
	std::cout << i;
	m.Delete("ori");
	i = m.find("ori");
	std::cout << i;

};
