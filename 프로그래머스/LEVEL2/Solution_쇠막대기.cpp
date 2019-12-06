#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
	int stack[100001];
	int top = -1;
	int sum = 0;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == ')') {
			if (top == 0) {
				if (i - stack[top] == 1) {
					top--;
					continue;
				}
				else {
					top--;
					sum++;
					continue;
				}
			}
			if (i - stack[top] != 1) {
				sum++;
				top--;
				continue;
			}
			sum += top--;
			
		}
		else {
			stack[++top] = i;
		}
	}

	return sum;
}

int main() {
	//string arrangement = "()(((()())(())()))(())";
	string arrangement = "(()())";
	cout << solution(arrangement);

}