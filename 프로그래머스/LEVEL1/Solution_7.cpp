#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int index = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (answer.empty()) {
			answer.push_back(arr[i]);
			index = 0;
			continue;
		}
		if (answer[index] == arr[i]) {
			continue;
		}
		else {
			answer.push_back(arr[i]);
			index++;
		}
	}
	

	return answer;
}
void main() {
	vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };
	solution(arr);
}