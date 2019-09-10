#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	for (int i = 0; i < seoul.size(); i++) {
		if (seoul[i].compare("Kim") == 0) {
			answer += "김서방은 ";
			answer += to_string(i);
			answer += "에 있다";
			break;
		}
	}


	return answer;
}
void main() {
	vector<string> seoul = { "Jane", "1", "1","1","1","1","1","1","1","1","1","1","1","1","1","1","Kim" };
	cout << solution(seoul);
}