#include <iostream>
#include <string>
using namespace std;

char map[101][101];
int visited[101][101][81]; 
int K;
int N;
int M;
string goal;
int dir[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int dfs(int a, int b, int idx, int cnt) {
	if (visited[a][b][idx] != -1) { //방문했던데면 리턴
		return visited[a][b][idx];
	}
	if (idx >= goal.size()) { //다 채웠으면 1
		return visited[a][b][idx] = 1;
	}
	if (cnt >= goal.size()) { //못 채웠으면 0
		return visited[a][b][idx] = 0;
	}
	int sum = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = a + i*dir[j][0];
			int ny = b + i*dir[j][1];
			if (nx >= N || ny >= M || nx < 0 || ny < 0) continue;
			if (map[nx][ny] == goal[idx]) {
				sum += dfs(nx, ny, idx + 1, cnt + 1);
			}
		}
	}
	return visited[a][b][idx] = sum;
}


int main() {
	cin >> N >> M >> K;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];
		}
	}
	cin >> goal;
	int hap = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k <= 80; k++) {
				visited[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == goal[0]) {
				if (visited[i][j][0] == -1) {
					visited[i][j][0] = dfs(i, j, 1, 1);
				}
				hap += visited[i][j][0];
			}
		}
	}
	cout << hap;
}