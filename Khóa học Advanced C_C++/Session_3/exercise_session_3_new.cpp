#include <iostream>
#include <stdio.h>

///////////////////////////////////////////////////////
/*
it should print like this

cat: child of Fuff and Mie is cat
dog: child of Mick and Fuff like a dog is dog
MickPinky is dog
horse: child of Pinky and Fuff like a horse is horse

*/ 
//////////////////////////////////////////////////////

namespace Earth {

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

class Dog;
class Cat;
class Horse;

class Dog : public Animal {

public:
	Dog(std::string);
};

class Cat : public Animal {
public:
	Cat(std::string);
	Cat(const Cat &);
	Cat operator + (const Cat &) const;
	operator Dog ();
	operator Horse ();
};	

class Horse : public Animal {
public:
	Horse(std::string);
	Horse operator + (const Horse &) const;
};

Dog::Dog(std::string name) : Animal(name, "dog"){
};

Cat::Cat(std::string name) : Animal(name, "cat"){
};

Cat::Cat(const Cat & rhs) : Animal(rhs.name(), "cat"){
};

Cat Cat::operator + (const Cat & rhs) const {
	return Cat("cat: child of " + name() + " and " + rhs.name());
};

Cat::operator Dog (){
	return Dog(name() + " like a dog");
} 

Cat::operator Horse () {
	return Horse(name() + " like a horse");
}

Horse::Horse(std::string name) : Animal(name, "horse"){
};

Horse Horse::operator + (const  Horse & rhs) const {
	return Horse("horse: child of " + name() + " and " + rhs.name());
} 

Dog operator + (const Dog & lhs, const Dog & rhs) {
	return Dog("dog: child of " + lhs.name() + " and " + rhs.name());
}
} // namespace Earth

int main() {

	using namespace Earth;
	
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
	
	Horse h2 = h + (Horse) c; // conversion operator
	h2.speak();
	
	return 0;
}
