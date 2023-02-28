#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<long long, long long>pll;
int main() {
	int N;
	cin >> N;
	priority_queue<pll,vector<pll>,greater<pll>>pq;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push({ input,0 });
	}
	if (N == 1)cout << 0;
	else{
		while (pq.size() > 1) {
			int curr = pq.top().first;
			int sum = pq.top().second;
			pq.pop();
			curr += pq.top().first;
			sum += curr + pq.top().second;
			pq.pop();
			pq.push({ curr,sum });
		}
		cout << pq.top().second;
	}
}