#include<iostream>
using namespace std;

int N;
int M;
int mod = 1000000007;

long long factorial(int n) {
	long long res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
int main() {
	cin >> N >> M;
	
	long long nfact = factorial(N);
	long long kfact = factorial(M);
	long long n_kfact = factorial(N - M);
	
	long long denominator = factorial(N-M) * factorial(M) % mod;

	int index = mod - 2;
	long long fermatNum = 1;
	while (index > 0) {
		if(index % 2 == 1) {
			fermatNum *= denominator;
			fermatNum %= mod;
		}
		denominator = (denominator * denominator) % mod;
		index /= 2;
	}
	long long result = ((nfact)* fermatNum) % mod;
	
	cout << result;
}