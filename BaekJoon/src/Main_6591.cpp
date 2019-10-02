#include<iostream>
using namespace std;


int main() {
	while (1) {
		int f1, f2;
		cin >> f1 >> f2;
		if (f1 == 0 && f2 == 0) {
			break;
		}
		if (f1 - f2 < f2) {
			f2 = f1 - f2;
		}
		int div = 1;
		long long hap = 1;
		while (f2-->0) {
			hap *= f1--;
			hap /= div++;
		}
		cout << hap << endl;
	}
	return 0;

}