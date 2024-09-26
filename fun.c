#include <string.h>
#include <stdio.h>

int main(void) {
	char a[] = "";
	char b[] = "";
	printf("Result: %s", &strstr(a,b));
	return 1;
}
