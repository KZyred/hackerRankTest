#include <iostream>
#include <stdio.h>

///////////////////////////////////////////////////////*
/*
it should print like this

cat: child of Fuff and Mie is cat
dog: child of Mick and Fuff like a dog is dog
MickPinky is dog
horse: child of Pinky and Fuff like a horse is horse

*/ 
//////////////////////////////////////////////////////
class Animal {

	std::string _name;
	std::string _type;
	
	Animal(){
	}
protected: // can be called from derived class
	Animal(std::string name = "animal", std::string type = "UNKNOWN"): _name(name), _type(type){
	}
public:
	std::string name() const{
		return _name;
	}
	std::string type() const{
		return _type;
	}

	Animal operator + (const Animal & rhs) const { // overload operator
		return Animal(_name + rhs._name, _type);
	}
	
	void speak() const {
		std::cout << _name << " is " << _type << std::endl;
	}
};

class Dog : public Animal {
	// implement here
};

class Horse : public Animal {
	// implement here
};

class Cat : public Animal {
	// implement here
};

int main() {

	Dog d("Mick");
	Cat c("Fuff");
	Horse h("Pinky");
	
	Cat c2("Mie");
	
	Cat c3 = c + c2; // overload operator	
	c3.speak();
	
	Cat c4 = c3; // copy constructor
		
	Dog d2 = d + (Dog) c; // non-member operator
	d2.speak();
	
	Animal a = (Animal) d + (Animal) h; // member operator with explicit conversion in Animal
	a.speak();
	
	Horse h2 = h + c; // conversion operator
	h2.speak();
	
	return 0;
}
