#include <iostream>
#include <stdio.h>

class C {
	int member;
	
	public:
		C() : member(0){}
		C(int val) {
			member = val;
		}
		void setMember(const int & _member) {
			member = _member;
		}
		int getMember () const {
			return member;
		}
};

int main() {
	const int i = 27;
	C o1;
	o1.setMember(i);

	std::cout << "member is : " << o1.getMember() << std::endl;
	
	return 0;
}
