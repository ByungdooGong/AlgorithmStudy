#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int min = n > m ? n : m;
	int first;
	for (int i = min; i >=1; i--) {
		if (n%i == 0 && m%i == 0) {
			answer.push_back(i);
			first = i;
			break;
		}
	}
	int second = 1;
	second = (n / first) * m;
	answer.push_back(second);
	return answer;
}
void main() {
	
}