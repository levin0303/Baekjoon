#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int cp(const pii& a, const pii& b,const pii& c) {
	pii ab = { b.first - a.first,b.second - a.second };
	pii bc = { c.first - b.first,c.second - b.second };
	int crossProduct = ab.first * bc.second - bc.first * ab.second;
	if (crossProduct > 0)return 1;
	if (crossProduct < 0)return -1;
	else return 0;
}
int main() {
	//freopen("input.txt", "r", stdin);
	vector<pii>n(3);
	for (int i = 0; i < 3; i++) cin >> n[i].first >> n[i].second;
	cout<<cp(n[0], n[1], n[2]);
	return 0;
}