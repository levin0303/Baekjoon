#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(NULL);ios::sync_with_stdio(false);
	ll min, max;
	int cnt = 0;
	cin >> min >> max;
	ll diff = max - min + 1;
    ll N=sqrt(max);
    vector<ll>prime;
    vector<bool>isprime(N+1,true);
    vector<bool>nono(diff,true);
	for (ll i=2;i<=N;i++){
        if(!isprime[i])continue;
        prime.push_back(i);
        for(ll j=i*i;j<=N;j+=i)isprime[j]=false;
       }
    for(auto p:prime){
        ll x=p*p;
        for(ll i=(0+(x-min%x)%x);i<diff;i+=x)nono[i]=false;
        }
    for(auto a:nono)if(a)cnt++;
    cout<<cnt;
}





