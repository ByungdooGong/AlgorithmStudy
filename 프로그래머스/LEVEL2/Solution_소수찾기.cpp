#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string str;

int f(int number) {
	if (number < 2) return 0;
	for (int i = 2; i <= number/2; i++) {
		if (number%i == 0) {
			return 0;
		}
	}
	return 1;
}
int visited[100];
unordered_map<int, int> map;
int ans = 0;
void perm(int n, int cnt, string tmp) {
	if (cnt == n) {
		return;
	}
	for (int i = 0; i<n; i++) {
		if (!visited[i]) {
			tmp += str[i];
			visited[i] = 1;
			//cout << tmp << endl;
			if (!map[stoi(tmp)]) {
				map[stoi(tmp)] = 1;
				if (f(stoi(tmp))) {
				//cout << stoi(tmp) << endl;
					ans++;
				}
			}
			perm(n, cnt+1, tmp);
			visited[i] = 0;
			tmp = tmp.substr(0, tmp.size() - 1);
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	str = numbers;
	perm(str.size(), 0, "");
	answer = ans;
	return answer;
}

int main() {
	//string numbers = "17";
	string numbers = "011";
	cout << solution(numbers);

}