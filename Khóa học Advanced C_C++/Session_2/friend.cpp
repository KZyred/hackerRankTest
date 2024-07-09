#include <iostream>
#include <string>

using namespace std;

class Animal {
	string _name;
	string _type;
	string _sound;
	
	// this private constructor prevent construction of base class
	Animal() {}

protected:	
	// protected constructor allows derived class use it
	Animal (const string & n, const string & t, const string & s) :
		_name(n), _type(t), _sound(s){}
public:
	void speak() const;
	const string & name() {
		return _name;
	}
	const string & type() {
		return _type;
	}
	const string & sound() {
		return _sound;
	}
};

void Animal::speak() const{
	printf("%s the %s say %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

class Dog : public Animal {
	int _walked;

public:
	Dog (string n) : Animal(n, "dog", "woof"), _walked(0) {};
	int walk() {
		return ++_walked;
	}
};

class Cat : public Animal {
	int _petted;

public:
	Cat(string n) : Animal(n, "cat", "su su sum"), _petted(0) {};
	int pet() {
		return ++_petted;
	}
};

class Pig : public Animal {
	int _fed;
	
public:
	Pig(string n) : Animal(n, "pig", "oink"), _fed(0){};
	int feed() {
		return ++_fed;
	}
};

//class Robot {
//	string _name;
//	string _type;
//	int _worked;
//	
//public:
//	Robot(string n) : _name(n), _type("metal"), _worked(0){};
//	const string & type() {
//		return _type;
//	}
//	int work() {
//		return ++_worked;
//	}
//	
//	void urlgy_action(Animal & a){
//		a._name = _name;
//		a._type = _type;
//	}
//};

int main() {
	Dog d("Goofy");
	Cat c("Tom");
	Pig p("Piglet");
	//Robot r("Wall-e");
	
	d.speak();
	c.speak();
	p.speak();
	
	cout << "\nthe " << d.type() << " has been walked " << d.walk() << " times" << endl;
	cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
	cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;
	
	//r.work();
	//cout << "the " << r.type() << " has been worked " << r.work() << " times" << endl;
	
	return 0;
}
