#include <iostream>
#include <vector>
#include <string>
using namespace std;

int L;
string str;
vector<int> map[10007];
int ans = 0;
int mod = 10007;

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
	for (int i = 0; i < mod; i++) {
		map[i].clear();
	}

	long long code = (str[0] - 'a');
	long long d = 1;
	for (int i = 1; i < c; i++) {
		code *= 29;
		code %= mod;
		code += (str[i]-'a');
		code %= mod;
		d *= 29;
		d %= mod;
	}
	map[code].push_back(0);
	
	for (int i = 0; i < (str.size() - c); i++) {
		code -= (str[i] - 'a') * d;
		if (code < 0) {
			code = ((-code / mod + 1)*mod + code) % mod;
		}
		code *= 29;
		code %= mod;
		code += (str[i + c] - 'a');
		code %= mod;
		
		if (!map[code].empty()) {
			for (int j = 0; j < map[code].size(); j++) {
				if (real_match(map[code][j], i + 1, c)) {
					return 1;
				}
			}
		}
		map[code].push_back(i + 1);
	}
	
	return 0;
}

void binarySearch(int st, int end) {
	if (st < end) {
		int mid = (st + end + 1) / 2;
		if (!f(mid)) {
			binarySearch(st, mid-1);
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
	cout << ans<<'\n';
	return 0;
}
