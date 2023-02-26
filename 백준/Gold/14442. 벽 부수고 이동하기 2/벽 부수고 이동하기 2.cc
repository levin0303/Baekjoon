#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int N, M, K;
char mat[1000][1000];
bool visited[11][1000][1000];
bool check(int z, int y, int x) {
	return(y >= 0 && y < N&& x >= 0 && x < M && !visited[z][y][x]);
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)cin >> mat[i][j];
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<int>ans;
	q.push({ {0,0}, {0,1} });
	visited[0][0][0] = true;
	int level = 1;
	while (!q.empty()) {
		int xcurr = q.front().first.second;
		int ycurr = q.front().first.first;
		int wall = q.front().second.first;
		int level = q.front().second.second;
		q.pop();
		if (ycurr == N - 1 && xcurr == M - 1) {
			cout << level;
			return 0;
		}
		for (int j = 0; j < 4; j++) {
			int dy = ycurr + dir[j][1];
			int dx = xcurr + dir[j][0];
			if (check(wall, dy, dx)) {
				if (mat[dy][dx] == '1') {
					if (wall < K&&!visited[wall+1][dy][dx]) {
						q.push({ { dy,dx }, {wall + 1,level + 1} });
						visited[wall + 1][dy][dx] = true;
					}
				}
				else {
					q.push({ {dy,dx},{wall,level + 1 } });
					visited[wall][dy][dx] = true;
				}
			}
		}
	}
	cout << -1;
}