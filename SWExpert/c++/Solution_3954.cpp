#include<iostream>
using namespace std;

int a;
int b;
long long arr[1000001];
int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < sizeof(arr) / sizeof(long long); i++) {
		arr[i] = i;
	}
	
	for (int i = 2; i < sizeof(arr) / sizeof(long long); i++) {
		if (arr[i] == i) {
			arr[i] = i - 1;
			for (int j = 2; i*j < sizeof(arr) / sizeof(long long); j++) {
				arr[i*j] = arr[i*j]*(i-1)/i;
			}
		}
	}
	for (int i = 1; i+1 < sizeof(arr) / sizeof(long long); i++) {
		arr[i + 1] += arr[i];
	}
	for (int i = 1; i <= tc; i++) {
		cin >> a >> b;
		cout << "#" << i << " " << arr[b] - arr[a-1] << endl;
	}
}