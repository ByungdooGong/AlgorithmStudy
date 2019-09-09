#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int> b = { 2, 1, 2, 3, 2, 4, 2, 5 };
	vector<int> c = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	int res[3] = { 0, };
	int max = 0;

	auto iter = a.begin();
	for (int i = 0; i < answers.size(); i++) {
		if (iter == a.end()) {
			iter = a.begin();
		}
		if (*iter == answers[i]) {
			res[0]++;
		}
		iter++;
	}
	if (res[0] > max)
		max = res[0];

	iter = b.begin();
	for (int i = 0; i < answers.size(); i++) {
		if (iter == b.end()) {
			iter = b.begin();
		}
		if ((*iter) == answers[i]) {
			res[1]++;
		}
		iter++;
	}
	if (res[1] > max)
		max = res[1];

	iter = c.begin();
	for (int i = 0; i < answers.size(); i++) {
		if (iter == c.end()) {
			iter = c.begin();
		}
		if ((*iter) == answers[i]) {
			res[2]++;
		}
		iter++;
	}
	if (res[2] > max)
		max = res[2];

	for (int i = 0; i < 3; i++) {
		if (max == res[i]) {
			answer.push_back(i + 1);
		}
	}
	return answer;
}

void main() {
	vector<int> answers = { 1, 2, 3, 4, 5 };
	vector<int> res = solution(answers);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

}