#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <iterator>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for (int i = 0; i<phone_book.size(); i++) {
		for (int j = i + 1; j<phone_book.size(); j++) {
			if (phone_book[i].size()<phone_book[j].size()) {
				if (phone_book[i].compare(phone_book[j].substr(0, phone_book[i].size()))==0){
					return answer = false;
				}
			}
			else {
				if (phone_book[j].compare(phone_book[i].substr(0, phone_book[j].size())) == 0) {
					return answer = false;
				}
			}
		}
	}
	return answer;
}
int main() {
	cout << solution(vector<string> {"119", "97674223", "1195524421"});
}