#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>h;
ll middle(int s, int e) {
    int mid = (s + e) / 2;
    int lpos = mid, rpos = mid;
    int biggerPos = mid;
    ll min_val = h[mid];
    ll sum = h[mid];
    while (true) {
        if (lpos == s && rpos == e)break;
        if (lpos == s) {
            rpos++;
            min_val = min(min_val, h[rpos]);
            ll tmp = (rpos - s + 1) * min_val;
            sum = max( sum, tmp);
        }
        else if (rpos == e) {
            lpos--;
            min_val = min(min_val, h[lpos]);
            ll tmp = (e - lpos + 1) * min_val;
            sum = max(sum, tmp);
        }
        else {
            if (h[lpos - 1] > h[rpos + 1]) {
                lpos--;
                min_val = min(min_val, h[lpos]);
                ll tmp = (rpos - lpos + 1) * min_val;
                sum = max( sum, tmp);
            }
            else {
                rpos++;
                min_val = min(min_val, h[rpos]);
                ll tmp = (rpos - lpos + 1) * min_val;
                sum = max(sum, tmp);
            }
        }
    }
    return sum;
}
ll f(int s, int e) {
    if (s > e)return 0;
    if (s == e)return h[e];
    int mid = (s + e) / 2;
    ll left = f(s, mid);
    ll right = f(mid + 1, e);
    return max( {left, right,middle(s,e)});
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (true) {
        cin >> N;
        if (N == 0)break;
        h.resize(N);
        for (int i = 0; i < N; i++)cin >> h[i];
        cout << f(0, N - 1) << '\n';
    }
    return 0;
}