#include <stdio.h>

int main(void) {

	int a = 0;

	int* ab;

	ab = &a;
	
	printf("ab = ");

	scanf_s("%d", &(*ab));

	printf("a = %d", a);

	return 0;

}