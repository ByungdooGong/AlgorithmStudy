#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> mergeSort(vector<string> strings, int n, int st, int end) {
	if (st >= end) {
		return vector<string>{ strings[st] };
	}
	int mid = (st + end) / 2;
	vector<string> left = mergeSort(strings, n, st, mid);
	vector<string> right = mergeSort(strings, n, mid + 1, end);
	
	int ldx = 0;
	int rdx = 0;
	vector<string> res;
	while (ldx < left.size() && rdx<right.size()) {
		if (left[ldx][n] < right[rdx][n]) {
			res.push_back(left[ldx]);
			ldx++;
		}
		else if (left[ldx][n] == right[rdx][n]) {
			if (left[ldx].compare(right[rdx]) <= 1) {
				res.push_back(left[ldx]);
				ldx++;
			}
			else {
				res.push_back(right[rdx]);
				rdx++;
			}
		}
		else {
			res.push_back(right[rdx]);
			rdx++;
		}
	}
	while (ldx < left.size()) {
		res.push_back(left[ldx]);
		ldx++;
	}
	while (rdx < right.size()) {
		res.push_back(right[rdx]);
		rdx++;
	}
	return res;
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	
	answer = mergeSort(strings, n, 0, strings.size() - 1);


	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return answer;
}
void main() {
	vector<string> strings = { "sun", "bed", "car" };
	int n = 1;
	solution(strings, n);
}