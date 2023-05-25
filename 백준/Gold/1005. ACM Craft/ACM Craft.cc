#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
//int k;
//void dfs(vector<vector<int>>& adj,int n) {
//	bool flag = false;
//	for (int next : adj[n]) {
//		flag = true;
//		dfs(adj, next);
//	}
//	if (!flag)k = n;
//}
ll f(vector<vector<int>>& adj,vector<ll>& dp,const vector<int>& bt, int N) {
	if (dp[N] != -1)return dp[N];
	ll ans = 0;
	for (auto x : adj[N]) {
		ll tmp = f(adj, dp, bt, x);
		if (ans < tmp)ans = tmp;
	}
	dp[N] = ans+bt[N];
	return dp[N];
}
int main(){
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T-- > 0) {
		vector<int>bt;
		vector<vector<int>>adj;
		vector<ll>dp;
		int N, K, W;
		cin >> N >> K;
		dp.resize(N,-1);
		bt.resize(N);
		adj.resize(N);
		for (int i = 0; i < N; i++)cin >> bt[i];
		for (int i = 0; i < K; i++) {
			int u, v;
			cin >> u >> v;
			adj[v-1].push_back(u-1);
		}
		cin >> W;	
		cout << f(adj, dp, bt, W - 1) << endl;
	}
}
