#include<iostream>
using namespace std;
typedef long long ll;
ll a, b, c;
int main() {
	cin >> a >> b >> c;
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans = (ans %c* a % c)%c;
		}
		a = a * a % c;
		b /= 2;
	}
	cout << ans;
}