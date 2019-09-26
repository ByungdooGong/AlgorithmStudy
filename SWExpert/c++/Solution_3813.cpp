#include <iostream>
using namespace std;

int N;
int K;
int arr[200001];
int block[200001];


bool f(int c) {
	int tmp[200001];
	for (int i = 0; i < 200001; i++) {
		tmp[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		if (c >= arr[i]) {
			tmp[i] = 1;
		}
	}
	int cnt = 0;
	int index = 0;
	
	for (int i = 0; i < N; i++) {
		if (tmp[i] == 1) {
			cnt++;
			if (cnt == block[index]) {
				cnt = 0;
				index++;
			}
		}
		else {
			cnt = 0;
		}
		if (index >= K) return true;
	}
	return false;
}
int binarySearch(int min, int max) {
	int mid = (min + max) / 2;
	if (f(mid)) {
		if (!f(mid - 1)) {
			return mid;
		}
		return binarySearch(min, mid);
	}
	else {
		if (f(mid + 1)) {
			return mid + 1;
		}
		return binarySearch(mid, max);
	}
}


int main() {
	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> block[i];
		}
		cout<<"#"<<k<<" " << binarySearch(0, 200000)<<endl;
	}
}