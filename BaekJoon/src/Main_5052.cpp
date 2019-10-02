#include<iostream>
using namespace std;
#define MAXN 10000

int tc;
int N;
char buf[MAXN][11];

typedef struct trie {
	trie* link[10];
	bool end;

	trie() {
		for (int i = 0; i < 10; ++i) {
			link[i] = 0;
		}
		end = false;
	}
	void insert(char* str) {
		if (*str == '\0') {
			end = true;
			return;
		}
		int cur = *str - '0';
		if (!link[cur]) {
			link[cur] = new trie();
		}
		link[cur]->insert(str + 1);
		
	}
	bool find(char* str) {
		if (*str == '\0') {
			return 0;
		}
		if (end) {
			return 1;
		}
		int cur = *str - '0';
		return link[cur]->find(str + 1);
	}
};

int main() {
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		cin >> N;
		trie* root = new trie();
		for (int i = 0; i < N; i++) {
			cin >> buf[i];
			root->insert(buf[i]);
		}
		bool ans = true;
		for (int i = 0; i < N; i++) {
			if (root->find(buf[i])) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";

		
	}
}