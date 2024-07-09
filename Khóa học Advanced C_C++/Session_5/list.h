#ifndef _LIST_H_
#define _LIST_H_
#include <functional>
//#include "item.h"

class Item;

class List{
	std::string name;
	Item* list;
	size_t size;

public:
	List() : name(""){
	};
	List(const char * _name, Item* _list, size_t _size) : name(_name), list(_list), size(_size){
	};
	List(const List &); // copy constructor
	~List(){ // destructor
		//delete[] list;
	}
	List& operator =(const List&); // copy assignment operator
	
	using Traveler = std::function<void(Item*)>;
	void traverse(const Traveler&) const;
};
#endif // _LIST_H_

