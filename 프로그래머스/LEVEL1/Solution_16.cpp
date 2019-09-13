#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
	string answer = "";
	vector<string> arr = { "¼ö","¹Ú" };
	int index = 0;
	for (int i = 0; i < n; i++) {
		answer += arr[index];
		index++;
		if (index == 2) {
			index = 0;
		}
	}

	return answer;
}
void main() {
	cout<<solution(3);
}