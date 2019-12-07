#include<iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int tc;
int n;
string arr[20001];

bool comparator(string a, string b) {
	if (a.size() == b.size()) {
		if (a.compare(b) >= 0) {
			return 0;
		}
		else
			return 1;
	}
	else {
		return a.size() < b.size();
	}
}
struct CustomCompare {
	bool operator()(string a, string b) {
		if (a.size() == b.size()) {
			if (a.compare(b) >= 0) {
				return 1;
			}
			else
				return 0;
		}
		else {
			return a.size() > b.size();
		}
	}
};


int main() {
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> n;
		string tmp;
		set<string> s;
		priority_queue<string, vector<string>, CustomCompare> pq;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (s.find(tmp) == s.end()) {
				s.insert(tmp);
				pq.push(tmp);
			}
		}
		cout << "#" << k << "\n";
		while (!pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
		
		
		/*for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n, comparator);
		cout << "#" << k << endl;
		for (int i = 0; i < n; i++) {
			if (s.find(arr[i]) == s.end()) {
				s.insert(arr[i]);
				cout << arr[i] << endl;
			}
		}*/
	}
}