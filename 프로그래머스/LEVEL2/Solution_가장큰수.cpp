#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(vector<string> &reps, int i, int j) {
	string tmp = reps[i];
	reps[i] = reps[j];
	reps[j] = tmp;
}
int f(string a, string b) {
	if (a.size() == b.size()) {
		return b.compare(a);
	}
	string sum = a + b;
	string reverseSum = b + a;
	return reverseSum.compare(sum);
}

void quickSort(vector<string> &reps, int st, int end) {
	if (st >= end) {
		return;
	}
	int pivot = (st + end) / 2;
	int i = st;
	for (int j = st; j <= end; j++) {
		if (f(reps[j], reps[pivot])>=1) {
			if (pivot == i) {
				pivot = j;
			}
			swap(reps, i++, j);
		}
	}
	swap(reps, pivot, i);
	quickSort(reps, st, i-1);
	quickSort(reps, i + 1, end);
}


string solution(vector<int> numbers) {
	string answer = "";
	vector<string> reps;
	for (int i = 0; i < numbers.size(); i++) {
		reps.push_back(to_string(numbers[i]));
	}
	quickSort(reps, 0, reps.size() - 1);
	for (int i = 0; i < reps.size(); i++) {
		answer = reps[i] + answer;
	}
	int start = 0;
	while(start<answer.size()-1){
		if (answer[start] == '0') {
			answer = answer.substr(1);
		}
		else {
			break;
		}
	}
	return answer;
}

int main() {
	//vector<int> numbers = { 3, 30, 34, 5, 9 };
	vector<int> numbers = { 12, 1213 };
	//vector<int> numbers = { 12, 121 };
	solution(numbers);
}