#include "list.h"
#include <iostream>

List::List(const List & rhs){ // copy constructor
		list = new Item[rhs.size];
		std::copy(rhs.list, rhs.list + size, list);
		size = rhs.size;
		name = rhs.name;
}

List& List::operator =(const List& rhs) { // copy assignment operator
		if (this != &rhs){
			delete[] list;
			list = new Item[rhs.size];
			std::copy(rhs.list, rhs.list + size, list);
			size = rhs.size;
			name = rhs.name;
		}
		return *this;
}

void List::traverse(const Traveler& traveler) const {
	std::cout << "Traverse through list " << name << std::endl;
	for (int i = 0; i < size; ++i){
		list[i].traverse(traveler);
	}		 
}
