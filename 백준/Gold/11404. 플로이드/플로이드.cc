#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<vector<long long>>dist(n, vector<long long>(n, 2e9));
	for (int i = 0; i < n; i++)dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		long long u, v, w;
		cin >> u >> v >> w;
		dist[u - 1][v - 1] = min(dist[u - 1][v - 1], w);
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == 2e9)dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}