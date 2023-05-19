#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<double, double> pii;
vector<pii>v;
int N;
double cp(const pii& a, const pii& b, const pii& c) {
	pii ab = { b.first - a.first,b.second - a.second };
	pii ac = { c.first - a.first,c.second - a.second };
	double crossProduct = ab.first * ac.second - ac.first * ab.second;
	return crossProduct;
}
double f() {
	double sum = 0;
	for (int k = 2; k < N; k++) {
		sum += cp(v[0],v[k-1],v[k]);
	}
	return abs(sum / 2.0);
}
int main() {
	//freopen("input.txt", "r", stdin);
	cout.setf(ios::showpoint);cout.setf(ios::fixed);cout.precision(1);
	cin.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)cin >> v[i].first >> v[i].second;
	cout << f();
}