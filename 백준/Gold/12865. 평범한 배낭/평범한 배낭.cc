#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>wt;
vector<int>val;
vector<vector<int>>dp;
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(NULL); ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	wt.resize(N + 1,0);
	val.resize(N + 1, 0);
	dp.resize(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++) {
		cin >> wt[i] >> val[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (wt[i] > j)dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
			}
		}
	}
	cout << dp[N][K];
    return 0;
}