#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int days[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 0; i<a - 1; i++) {
		sum += days[i];
	}
	sum += b;
	string name[] = { "FRI","SAT","SUN","MON","TUE","WED","THU"};
	sum = (sum-1) % 7;

	return answer = name[sum];
}
void main() {
	cout << solution(5, 24);
}