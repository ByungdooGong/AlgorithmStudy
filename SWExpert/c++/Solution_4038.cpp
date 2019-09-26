#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	string b;
	string s;
	for (int k = 1; k <= tc; k++) {
		cin >> b >> s;
		int cnt = 0;
		for (int i = 0; i <= b.size() - s.size(); i++) {
			string token = b.substr(i, s.size());
			if (token.compare(s)==0)
				cnt++;
		}
		cout << "#" << k << " " << cnt << endl;
	}
}