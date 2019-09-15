#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int que[101] = { 0, };
	int front = -1;
	int back = -1;
	for (int i = 0; i<progresses.size(); i++) {
		int tmp = 100 - progresses[i];
		if (tmp%speeds[i] == 0) {
			if (back == -1 || (tmp / speeds[i])>que[back]) {
				que[++back] = tmp / speeds[i];
			}
			else {
				int temp = que[back];
				que[++back] = temp;
			}
		}
		else {
			if (back == -1 || (tmp / speeds[i]) + 1>que[back]) {
				que[++back] = (tmp / speeds[i]) + 1;
			}
			else {
				int temp = que[back];
				que[++back] = temp;
			}
		}
	}
	for (int i = front + 1; i <= back; i++) {
		int cnt = 1;
		int first = que[i];
		while (i + 1 <= back && first == que[i + 1]) {
			cnt++;
			i++;
		}
		answer.push_back(cnt);
	}

	return answer;
}