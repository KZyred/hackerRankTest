#include <stdio.h>

void foo(){
	static const char __func2__[] = "foo";
	printf("%s", __func2__);	
}
int main() {

	printf("%s, line:%s\n", __func__, __FILE__);
	foo();
	
	return 0;
}
