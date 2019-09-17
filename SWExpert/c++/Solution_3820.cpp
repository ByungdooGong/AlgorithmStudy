#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	double tmp1 = (b.first - 1)/(double)b.second;
	double tmp2 = (a.first - 1)/(double)a.second;
	if (tmp1 < tmp2) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		int n;
		cin >> n;
		pair<int, int> *arr = new pair<int, int>[n];
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			arr[i] = pair<int, int>(a, b);
		}
		sort(arr, arr + n, compare);
		long long v = 1;
		for (int i = 0; i < n; i++) {
			v = arr[i].first*v + arr[i].second;
			v = v % 1000000007;
		}
		cout << "#" << k << " " << v << "\n";
	}
}