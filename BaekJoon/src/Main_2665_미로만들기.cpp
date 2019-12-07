#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
int map[51][51];
//int visited[51][51];
int dp[51][51];
int dir[][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dp[0][0] = 0;
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		//visited[px][py] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = px + dir[i][0];
			int ny = py + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			//if (!visited[nx][ny]) {
			if (map[nx][ny] && (dp[px][py] < dp[nx][ny])) {
				dp[nx][ny] = dp[px][py];
				q.push(make_pair(nx, ny));
			}
			if (!map[nx][ny] && (dp[px][py] + 1 < dp[nx][ny])){
				dp[nx][ny] = dp[px][py]+1;
				q.push(make_pair(nx, ny));
			}
			//}
		}
	}
	return dp[n-1][n-1];
}

int main() {
	cin >> n;
	
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0xfffffff;
		}
	}
	cout<<bfs();
}