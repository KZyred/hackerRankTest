#include <iostream>
#include <memory>

using namespace std;

class Rectangle {
private:
	int length;
	int breadth;
	
public:
	Rectangle() : length(0), breadth(0) {
		std::cout << "default ctor\n";
	}
	Rectangle(int l, int b) {
		std::cout << "ctor\n";
		length = l;
		breadth = b;
	}
	~Rectangle() {
		std::cout << "dtor\n";
	}
	
	int area() const {
		return length * breadth;
	}
};

int main() {
	shared_ptr<Rectangle> P1(new Rectangle(12, 5));
	//auto P1 = std::make_shared<Rectangle>(12,5);
	cout << "Area is: " << P1->area() << endl;
	
	shared_ptr<Rectangle> P2;
	P2 = P1; // it's ok with a shared_ptr
	
	cout << "Area is: " << P2->area() << endl;
	
	cout << "Reference count is: " << P1.use_count() << endl;
	
	P1.reset(); // just reset P1 pointer, not call destructor of Rectangle
	
	if (P2 != nullptr)
		std::cout << "Area of P2 is: " << P2->area() << std::endl;
	
	if (P1 != nullptr)
		cout << "Reference count is: " << P1.use_count() << endl;
	else
		cout << "Shared ptr P1 has been reset\n";
	return 0;
}
