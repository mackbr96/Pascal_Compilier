#include <stdio.h>

int foo(int x, int y, int a, int b, int c, int d) {
	return x + y;
}

int main() {
	int y = 9;
	int z = 8;
	int x = foo(y,z, z, y,z,y);
}
