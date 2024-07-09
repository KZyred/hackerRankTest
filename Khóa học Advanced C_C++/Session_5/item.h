#ifndef _ITEM_H_
#define _ITEM_H_

#include <iostream>
#include "list.h"

class Item {
	std::string employee;
	int age;

public:	
	Item(){
	}
	
	Item(std::string e, int a) : employee(e), age(a){
	}
	
	void traverse(const List::Traveler & traveler){
		traveler(this);
	}
	void print_info(){
		std::cout << "Employee " << employee << " has age " << age << std::endl;
	}
};
#endif // _ITEM_H_
