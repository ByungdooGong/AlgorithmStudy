#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			answer += ' ';
			flag = 0;
			continue;
		}
		if (flag % 2 == 0) {
			if (s[i] >= 'a') {
				int tmp = s[i] - 'a';
				answer += 'A' + tmp;
				flag++;
				continue;
			}
		}
		else {
			if (s[i] < 'a') {
				int tmp = s[i] - 'A';
				answer += 'a' + tmp;
				flag++;
				continue;
			}
		}
		answer += s[i];
		flag++;
	}

	return answer;
}
void main() {
	string s = "taA hello world";
	cout << solution(s);
}