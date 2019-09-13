#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			answer += ' ';
			continue;
		}
		if (s[i] - 'a' >= 0) {
			int tmp = s[i] - 'a' + n;
			if (tmp >= 26) {
				answer += 'a' + tmp - 26;
				continue;
			}
			answer += 'a' + tmp;
		}
		else {
			int tmp = s[i] - 'A' + n;
			if (tmp >= 26) {
				answer += 'A' + tmp - 26;
				continue;
			}
			answer += 'A' + tmp;
		}
	}

	return answer;
}
void main() {
	//string s = "AB";
	//string s = "z";
	string s = "a Z z";
	cout << solution(s, 25);

}