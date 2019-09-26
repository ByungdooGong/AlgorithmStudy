#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L;
string str;
vector<pair<int, int>> map;
int ans = 0;
unsigned long long mod = 0xFFFFFFFFFFFFFFFF;

bool real_match(int s1, int s2, int L)
{
	for (int i = 0; i < L; i++) {
		if (str[s1 + i] != str[s2 + i]) {
			return false;
		}
	}
	return true;
}

int f(int c) {
	map.clear();

	unsigned long long code = (str[0] - 'a');
	unsigned long long d = 1;
	for (int i = 1; i < c; i++) {
		code *= 29;
		code %= mod;
		code += (str[i] - 'a');
		code %= mod;
		d *= 29;
		d %= mod;
	}
	map.push_back(pair<int, int>(code, 0));

	for (int i = 0; i < (str.size() - c); i++) {
		code -= (str[i] - 'a') * d;
		if (code < 0) {
			code = (code + mod) % mod;
		}
		code *= 29;
		code %= mod;
		code += (str[i + c] - 'a');
		code %= mod;
		
		map.push_back(pair<int, int>(code, i + 1));
		
	}
	sort(map.begin(), map.end());

	for (int i = 1; i < map.size(); i++) {
		if (map[i].first == map[i-1].first) {
			if (real_match(map[i].second, map[i - 1].second, c)) {
				return 1;
			}
		}
	}

	return 0;
}

void binarySearch(int st, int end) {
	if (st < end) {
		int mid = (st + end + 1) / 2;
		if (!f(mid)) {
			binarySearch(st, mid - 1);
		}
		else {
			ans = mid;
			binarySearch(mid, end);
		}
	}
}
int main() {
	cin >> L;
	cin >> str;
	binarySearch(0, L);
	cout << ans << '\n';
	return 0;
}
