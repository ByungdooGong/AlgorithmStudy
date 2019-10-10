#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int tmp[28];
	for (int k = 0; k < skill_trees.size(); k++) {
		for (int i = 0; i < 28; i++) {
			tmp[i] = -2;
		}
		int prev = skill[0] - 'A';
		tmp[prev] = -1;
		for (int j = 1; j < skill.length(); j++) {
			tmp[skill[j] - 'A'] = prev;
			prev = skill[j] - 'A';
		}
		int flag = 0;
		for (int p = 0; p < skill_trees[k].length(); p++) {
			char word = skill_trees[k][p];
			if (tmp[word - 'A'] == -1) {
				tmp[word - 'A'] = -2;
				continue;
			}
			if (tmp[word - 'A'] == -2) {
				continue;
			}
			if (tmp[word-'A']>=0 && tmp[tmp[word - 'A']] == -2) {
				tmp[word - 'A'] = -2;
				continue;
			}
			flag = 1;
			break;
		}
		if (flag == 0) answer++;
	}
	return answer;
}

int main() {
	string skill = "CBD";
	vector<string> skill_trees = { "BACDE", "CBADF", "AECB", "BDA" };
	solution(skill, skill_trees);
}