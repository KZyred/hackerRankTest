#include <iostream>
#include <memory>
//#include "work.h"

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
	std::shared_ptr<Rectangle> s1(new Rectangle(23, 5));
	auto c1 = s1;
	auto c2 = s1;
	auto c3 = s1;
	auto c4 = s1;
	auto c5 = s1;
	
	cout << "ref count = " << s1.use_count() << endl;
	
 	//weak_ptr<Rectangle> w1(new Rectangle(13, 6));
 	weak_ptr<Rectangle> w1 = s1;
 	int tmp = w1.use_count();
 	if (auto sp = w1.lock())
		cout << "Area is: " << sp->area() << " count of sp = " << sp.use_count() << " count of w1 = " << tmp << endl;
	s1.reset();
	
	weak_ptr<Rectangle> w2;
	//w2 = w1;
	 cout << "w1 count is " << w1.use_count() << ". w2 count is " << w2.use_count() << endl;
	//w2.reset();

	//c5.reset();
	//c4.reset();
	//c3.reset();
	//c2.reset();
	//c1.reset();
	
	if (!w1.expired())
	 	cout << "w1 count is " << w1.use_count() << ". shared_ptr count is " << w1.lock().use_count() << endl;
	else
		cout << "w1 is expired\n";

//	Manager* m = new Manager();
//	Employee* e = new Employee();
//		
//	cout << "End program.\n";
	return 0;
}

