#include<iostream>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int>pii;
vector<vector<pii>>adj;
vector<bool>visited;
vector<int>dist;
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	int V, E, K;
	cin >> V >> E >> K;
	K--;
	adj.resize(V);
	visited.resize(V);
	dist.resize(V, 1e9);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back({ v - 1,w });
	}
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	dist[K] = 0;
	pq.push({ dist[K],K});
	while (!pq.empty()) {
		int curr = pq.top().second;
		if (visited[curr]) {
			pq.pop();
			continue;
		}
		pq.pop();
		visited[curr] = true;
		for (auto x : adj[curr]) {
			if (!visited[x.first]) {
				if (dist[x.first] > dist[curr] + x.second) {
					dist[x.first] = dist[curr] + x.second;
					pq.push({ dist[x.first],x.first });
				}
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[i] == 1e9)cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}