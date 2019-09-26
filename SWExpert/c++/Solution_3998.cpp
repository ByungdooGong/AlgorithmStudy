#include<iostream>
using namespace std;
int n;
int arr[100001];
int tmp[100001];
int cnt = 0;
void merge(int st, int mid, int end) {
	int p = st;
	int q = mid + 1;
	int r = st;
	while (p<=mid && q<=end) {
		if (arr[p] <= arr[q]) {
			tmp[r++] = arr[p++];
		}
		else {
			tmp[r++] = arr[q++];
			cnt += (mid - p + 1);
		}
	}
	while (p <= mid) {
		tmp[r++] = arr[p++];
	}
	while (q <= end) {
		tmp[r++] = arr[q++];
	}
	for (int i = st; i <= end; i++) {
		arr[i] = tmp[i];
	}
}
void partition(int st, int end) {
	if (st < end) {
		int mid = (st + end) / 2;
		partition(st, mid);
		partition(mid + 1, end);
		merge(st, mid, end);
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		partition(0, n - 1);
		cout << "#" << k << " " << cnt << endl;
	}
	
}