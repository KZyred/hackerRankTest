#include <stdio.h>

using namespace std;

class c1
{
	// this is private zone
	int _value = 0;
	c1(); // default constructor

public:
	c1(const int &value) : _value(value) {} // constructor with one argument
	void setValue(const int &value)
	{
		_value = value;
	}
	int getValue() const
	{
		return _value;
	}
};

void function(const c1 &c)
{
	printf("value from function is %d\n", c.getValue());
}

int main()
{
	c1 c = 'd';
	// c1 c2;
	printf("value is %d\n", c.getValue());
	function('d');

	return 0;
}
