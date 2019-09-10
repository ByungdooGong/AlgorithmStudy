#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int mid = s.size() / 2;
	if (s.size() % 2 == 1) {
		answer += s[mid];
	}
	else {
		mid = mid - 1;
		answer = s.substr(mid, 2);
	}
	cout << answer;
	return answer;
}

void main() {
	string s = "abcdef";
	solution(s);
}