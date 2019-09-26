#include <iostream>
using namespace std;

int N;
int K;
int arr[100001];

bool f(int c) {
	int hap = 0;
	int tmp[100001];
	for (int i = 0; i < N; i++) {
		tmp[i] = arr[i];
	}
	for (int i = 0; i < N - 1; i++) {
		if (tmp[i] + c < tmp[i + 1]) {
			hap += tmp[i + 1] - (tmp[i] + c);
			tmp[i + 1] = tmp[i] + c;
		}
	}
	for (int i = N - 1; i >= 1; i--) {
		if (tmp[i] + c < tmp[i - 1]) {
			hap += tmp[i - 1] - (tmp[i] + c);
			tmp[i - 1] = tmp[i] + c;
		}
	}
	if (hap <= K) return true;
	return false;
}
int binarySearch(int min, int max) {
	int mid = (min + max) / 2;
	if (f(mid)) {
		if (!f(mid - 1)) {
			return mid;
		}
		else {
			return binarySearch(min, mid);
		}
	}
	else {
		if (f(mid + 1)) {
			return mid + 1;
		}
		else {
			return binarySearch(mid, max);
		}
	}
}
int main() {
	int tc;
	cin >> tc;;
	for (int k = 1; k <= tc; k++) {
		cin >> N >> K;
		for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout << "#" << k << " " << binarySearch(0, 100000) << endl;
	}
}