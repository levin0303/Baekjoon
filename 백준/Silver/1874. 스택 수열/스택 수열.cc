#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
	cin.tie(NULL); ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	int curr = 0;
	vector<int> v(N);
	stack<int>tmp;
	vector<char>ans;
	for (int i = 0; i < N; i++)cin >> v[i];
	for (int i = 1; i <= N; i++) {
		tmp.push(i);
		ans.push_back('+');
		while (!tmp.empty() && tmp.top() == v[curr]) {
			tmp.pop();
			ans.push_back('-');
			curr++;
		}
	}
	if (!tmp.empty())cout << "NO";
	else for (auto x : ans)cout << x << '\n';
	
}
