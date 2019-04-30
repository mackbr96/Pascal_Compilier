#include <stdio.h>
int main() {
	int x = -5;
	int y = 9;
	x = y * x;
	fprintf(stderr, "%d\n", x);
}
