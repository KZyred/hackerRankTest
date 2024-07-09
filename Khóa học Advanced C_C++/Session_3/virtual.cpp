#include <stdio.h>

class Grand {
	int f0;
	
public:
	Grand(){
//		printf("Grand constructor is called\n");
	}
	void speak() const {
		printf("This is a grand object speaking\n");
	}
};

class Dad : public Grand {
	int f1;
	
public:
	Dad(){
//		printf("Dad constructor is called\n");
	}
	void speak() const {
		printf("This is a dad object speaking\n");
	}
};

class Son : public Dad {
	int f2;
	
public:
	Son(){
//		printf("Son constructor is called\n");
	}
	void speak() const {
		printf("This is a son object speaking\n");
	}
};

void saying(const Grand & g) {
	g.speak();
}
int main() {
	Grand g;
	Dad d;
	Son s;	
	
	s.speak();
	s.Dad::speak();
	s.Grand::speak();
	
//  saying(g);
//	saying(d);
//	saying(s);
	
	return 0;
}
