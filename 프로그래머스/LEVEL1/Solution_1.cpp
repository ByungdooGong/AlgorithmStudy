#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> hashmap;
	
	for (int i = 0; i < participant.size(); i++) {
		auto itr = hashmap.find(participant[i]);
		if (itr != hashmap.end())
			itr->second++;
		else
			hashmap.insert(unordered_map<string, int>::value_type(participant[i], 1));
	}
	
	for (int i = 0; i < completion.size(); i++) {
		auto itr = hashmap.find(completion[i]);
		if ((itr->second) == 1) {
			hashmap.erase(itr);
		}
		else {
			itr->second--;
		}
	}
	auto itr = hashmap.begin();
	
	return itr->first;
}

void main() {
	vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
	vector<string> completion = { "stanko", "ana", "mislav" };
	cout << solution(participant, completion);
}