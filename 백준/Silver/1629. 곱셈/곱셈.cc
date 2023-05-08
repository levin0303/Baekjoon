#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c;
ll f(ll x) {
    if (x == 0)return 1;
    if (x == 1)return a % c;
    ll tmp = f(x / 2)%c;
    if (x % 2 == 0)return (tmp * tmp)%c;
    if (x % 2 == 1)return ((tmp * tmp)%c * a % c)%c;
}
int main(){
    cin >> a >> b >> c;
    cout << f(b);
}
