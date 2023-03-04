#include<iostream>
#include<cmath>
using namespace std;
int board[100001] = { 0, };
int dp(int n);
int main() {

	int N;
	cin >> N;
	cout<<dp(N);
}
int dp(int n) {
	if (n <= 3)return n;
	if (board[n] != 0)return board[n];
	int smaller = 200001;
	int bound = static_cast<int>(sqrt(n));
	for (int i = 1; i <= bound; i++) {
		smaller = min(smaller, dp(n - i * i));
	}
	board[n] = smaller + 1;
	return board[n];
}