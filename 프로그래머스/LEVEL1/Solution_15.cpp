#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;

	int dp[1000001];
	for (int i = 1; i <= 1000000; i++) {
		dp[i] = 1;
	}
	dp[1] = 0;
	for (int i = 2; i < n; i++) {
		if (dp[i] == 1){
			for (int j = 2; j*i <= n; j++) {
				dp[j*i] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		answer += dp[i];
	}
	return answer;
}
void main() {
	cout<<solution(10);
}