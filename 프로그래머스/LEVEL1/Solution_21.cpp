#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> arr) {
	vector<int> answer;
	int max = 0x7FFFFFFF;
	int index = -1; 
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < max) {
			max = arr[i];
			index = i;
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		if(i!=index){
			answer.push_back(arr[i]);
		}
	}
	if (answer.empty()) {
		answer.push_back(-1);
	}
	return answer;
}
void main() {
	vector<int> arr = { 4, 3, 2, 1 };
	cout << max;


}