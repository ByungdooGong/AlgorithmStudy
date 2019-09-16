#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> bridge;
	for (int i = 0; i < bridge_length; i++) {
		bridge.push(0);
	}
	int hap = 0;
	int index = 0;
	while (1) {
		answer++;
		hap -= bridge.front();
		bridge.pop();
		if (index < truck_weights.size() && hap + truck_weights[index] < weight) {
			hap += truck_weights[index];
			bridge.push(truck_weights[index]);
			if (index < truck_weights.size()) {
				index++;
			}
		}
		else {
			bridge.push(0);
		}
		//cout <<bridge.front()<< " " << bridge.back()<<" "<<index<<endl;
		if (hap == 0 && index == truck_weights.size()) {
			break;
		}
	}
	return answer;
}
void main() {
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10 };
	cout << solution(bridge_length, weight, truck_weights);
}