#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	vector<int> tmp;
	for (int i = 0; i < commands.size(); i++) {
		int t1 = commands[i][0]-1;
		int t2 = commands[i][1]-1;
		int t3 = commands[i][2]-1;
		for (int j = t1; j <= t2; j++) {
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());
		answer.push_back(*(tmp.begin() + t3));
		tmp.clear();
	}

	return answer;
}
void main() {
	vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
	solution(array, commands);
}