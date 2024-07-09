#include <iostream>
#include <cmath>

using namespace std;
class My_Complex {
   private:
      double real, imag;
   public:
      My_Complex(double re = 0.0, double img = 0.0) : real(re), imag(img) {} //default constructor
      double mag() {    //normal function to get modulus/aboslute value
         return getModulus();
      }
      operator double () { //Conversion operator to gen modulus/aboslute value
         return getModulus();
      }
   private:
      double getModulus() { //Find modulus/aboslute value of complex object
         return sqrt(real * real + imag * imag);
      }
};

//template <class Type>
//class smartref {
//public:
//		smartref() : data(new Type){
//		}
//		operator Type& () { // conversion operator
//			std::cout << "calling conversion operator\n";
//			return *data;
//		}
//private:
//		Type* data;
//}; 

class person {
	
	public:
		void think() {
			std::cout << "I'm thinking\n";
		}
};
int main() {
   My_Complex complex(10.0, 6.0);
   cout << "Modulus using normal function: " << complex.mag() << endl;
   cout << "Modulus using conversion operator: " << complex << endl;
   
//   smartref<person> p;
//   p.think();

}
