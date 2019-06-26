#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int T;

int main() {
	scanf("%d", &T);
	int a, b;
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

}