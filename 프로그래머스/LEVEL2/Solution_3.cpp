#include <string>
#include <vector>
#include <iostream>
using namespace std;
string solution(int n) {
	string answer = "";
	string arr[] = { "1", "2", "4" };
	int lv = n;
	while (lv>0) {
		lv--;
		answer = arr[lv % 3]+ answer;
		lv /= 3;
	}
	return answer;
}
void main() {
	cout << solution(500);
}