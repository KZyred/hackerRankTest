#include <iostream>
#include <stdio.h>

class C
{
	int member;

public:
	C() : member(0) {}
	C(int val)
	{
		member = val;
	}
	void setMember(const int &_member)
	{
		member = _member;
	}
	int getMember() const
	{
		return member;
	}
};

int main()
{
	const int i = 27;
	C o1;
	o1.setMember(i);
	// nếu sử dụng tham số const, thì buộc đối số cũng phải là const (điều này sai, đã thử bỏ const những compile không báo lỗi)

	std::cout << "member is : " << o1.getMember() << std::endl;

	return 0;
}
