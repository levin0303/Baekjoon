#include <iostream>
using namespace std;
typedef long long ll;
const int p = 1000000007;
ll N, K;
ll power(ll a,ll b) {
    if (b == 0)return 1;
    if (b == 1)return a;
    ll tmp = power(a, b / 2);
    if (b % 2 == 0)return (tmp%p * tmp%p) % p;
    if (b % 2 == 1)return ((tmp % p * tmp % p) % p * a) % p;
}
int main(){
    cin >> N >> K;
    ll x=1, y = 1;
    for (ll i = N-K+1; i <= N; i++) {
        x *= i;
        x %= p;
    }
    for (ll j = 1; j <= K; j++) {
        y *= j;
        y %= p;
    }
    cout <<(x* power(y, p - 2))%p;
    return 0;
}
