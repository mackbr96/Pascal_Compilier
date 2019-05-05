#include <stdio.h>
int outside = 5;

int foo(int x) {
	return outside + x;
}

int main() {
	int y = 9;
	int x = foo(y);
}
