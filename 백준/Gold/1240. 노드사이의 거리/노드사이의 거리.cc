#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int N, M;
typedef pair<int, int> pii;
vector<vector<pii>>adj;
vector<bool>visited;
int dfs(int curr,int target,int dist) {
	int ans = 2e9;
	if (curr == target)return dist;
	visited[curr] = true;
	for (auto next : adj[curr]) {
		if (!visited[next.first]) {
			ans=min(ans,dfs(next.first, target, dist + next.second));
		}
	}
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	adj.resize(N);
	visited.resize(N, false);
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1,w });
		adj[v - 1].push_back({ u - 1,w });
	}
	for (int i = 0; i < M; i++) {
		fill(visited.begin(), visited.end(), false);
		int s, e;
		cin >> s >> e;
		cout << dfs(s-1, e-1, 0) << endl;
	}



}