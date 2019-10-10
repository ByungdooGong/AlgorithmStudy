#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> rev;
	int stack[101];
	int top = -1;
	for (int i = 0; i < heights.size(); i++) {
		stack[++top] = heights[i];
	}
	while (top >= 0) {
		int tmp = top;
		int flag = 0;
		while (top >= 0) {
			if (stack[tmp] < stack[top]) {
				rev.push_back(top+1);
				flag = 1;
				break;
			}
			else {
				top--;
			}
		}
		if (flag == 0) {
			rev.push_back(0);
		}
		top = tmp - 1;
	}
	vector<int> answer;
	for (int i = rev.size()-1; i >= 0; i--) {
		answer.push_back(rev[i]);
	}
		
	return answer;
}

int main() {
	vector<int> heights = { 6, 9, 5, 7, 4 };
	solution(heights);
}
