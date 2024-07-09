#include <iostream>
#include "list.h"
#include "item.h"
#include "list.cpp"

int main() {
	
	Item* array = new Item[3];
	array[0] = Item("Adam", 34);
	array[1] = Item("Eve", 26);
	array[2] = Item("Bob", 22);
	
	int count = 0;
	
	List list("Adam's company", array, 3);
	
	list.traverse([&](Item* item){
		//sstd::cout << "k outside of lambda function is " << k << std::endl;
		++count;
		item->print_info();
	});
	std::cout << "list has " << count << " elements." << std::endl;
	delete[] array;
	return 0;
}
