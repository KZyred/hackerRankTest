#include <iostream>

#define PI 3.1415

int main() {
	float radius = 4.0f;
	float area;
	area = PI * radius * radius;
	
	std::cout << "Area of circle with radius = " << radius << " is: " << area << std::endl;
	
	return 0;
}
