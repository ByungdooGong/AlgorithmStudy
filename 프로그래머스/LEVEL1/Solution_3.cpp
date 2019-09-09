#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	
	int cnt = 0;
	int arr[31] = { 0, };
	for (int i = 0; i < lost.size(); i++) {
		arr[lost[i]] = -1;
	}
	for (int j = 0; j < reserve.size(); j++) {
		if (arr[reserve[j]] == -1) {
			arr[reserve[j]] = 0;
			reserve[j] = -1;
			continue;
		}
	}
	sort(reserve.begin(), reserve.end());
	for (int j = 0; j < reserve.size(); j++) {
		if (reserve[j] >= 1 && arr[reserve[j] - 1] == -1) {
			arr[reserve[j] - 1] = 0;
			continue;
		}
		if (reserve[j] < 30 && arr[reserve[j] + 1] == -1) {
			arr[reserve[j] + 1] = 0;
			continue;
		}
	}
	
	for (int i = 0; i < 31; i++) {
		if (arr[i] == -1) {
			cnt++;
		}
	}
	return answer = n-cnt;
}
void main() {
	int n = 10;
	vector<int> lost = { 8, 10, 12, 15 };
	vector<int> reserve = { 11, 9 };

	cout << solution(n, lost, reserve);
}