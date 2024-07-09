#include <iostream>
#include <memory>

using namespace std;

class Rectangle {
private:
	int length;
	int breadth;
	
public:
	Rectangle() : length(0), breadth(0){
		std::cout << "default ctor\n";
	}
	Rectangle(int l, int b){
		std::cout << "ctor\n";
		length = l;
		breadth = b;
	}
	~Rectangle(){
		std::cout << "dtor\n";
	}
	
	int area() const {
		return length * breadth;
	}
};


int main() {
	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << "Area of P1 is: " << P1->area() << endl;
	
	//std::unique_ptr<Rectangle> P2(P1); // P2 tries to point to which P1 is pointing
	unique_ptr<Rectangle> P2;
	P2 = std::move(P1);
	
	cout << "Area of P2 is: " << P2->area() << endl;
	
	P2.reset(new Rectangle(13, 7));
	
	if (P1 != nullptr)
		cout << "Area of P1 is: " << P1->area() << endl; // should this work?
	else {
		cout << "P1 is nullptr\n";
	}
//	auto b = std::make_unique<Rectangle>(2,6);
//	cout << "Area of b is: " << b->area() << endl;
	
	
	return 0;
}
