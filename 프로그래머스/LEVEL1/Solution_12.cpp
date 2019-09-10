#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";
	int arr[101] = { 0, };
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - '0']++;
	}
	for (int i = 99; i >= 0; i--) {
		if (arr[i] != 0) {
			answer += (char)(i + '0');
			arr[i]--;
			i++;
		}
	}
	cout << answer;
	return answer;
}
void main() {
	string s = "Zbcdefg";
	solution(s);
}