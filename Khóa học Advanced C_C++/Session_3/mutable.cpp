#include <iostream>

using namespace std;

class Test{
public:
	int x;
	mutable int y;
	
	Test() : x(0), y(0){
	}
	Test(int, int);
	void changeX(int);
	void changeX(int) const;
	void changeY(int) const;
};

Test::Test(int x, int y){
	this->x = x;
	this->y = y;
}

void Test::changeX(int x){
	this->x = x;
}

void Test::changeX(int x) const{
	cout << "This is read-only function" << endl;
	//this->x = x;
}

void Test::changeY(int y) const{
	this->y = y;
}

int main(){
	
	Test t = {3, 6}; // implicit conversion constructor
	t.changeX(2);
	const Test t2 = {4, 8};
	t2.changeY(9);
	
	cout << "t.changeX = " << t.x << " t2.changeY = " << t2.y << endl;
	
	return 0;
}
