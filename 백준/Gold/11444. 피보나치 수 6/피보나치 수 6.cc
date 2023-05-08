#include <iostream>
#include<vector>
const int DIVISOR = 1000000007;
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
class matrix {
public:
    matrix() {
        m_mat.resize(2, vector<ll>(2, 0));
        m_mat[0][0] = m_mat[0][1] = m_mat[1][0] = 1;
    }
    ll accessor();
    friend matrix operator*(const matrix&,const matrix&);
    //friend matrix& operator*(const matrix&, const ll k);
private:
    mat m_mat;
};
const matrix a;
matrix f(ll x) {
    if (x == 1)return a;
    matrix tmp = f(x / 2);
    if (x % 2 == 0)return (tmp * tmp);
    if (x % 2 == 1)return ((tmp * tmp)*a);
}
int main(){
    ll x;
    cin >> x;
    if (x <= 1) {
        cout << x;
        return 0;
    }
    matrix a = f(x - 1);
    cout << a.accessor();
}
matrix operator*(const matrix& a, const matrix& b) {
    matrix kk;
    ll tmp = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmp += (a.m_mat[i][k]%DIVISOR * b.m_mat[k][j]%DIVISOR)%DIVISOR;
            }
            kk.m_mat[i][j] =tmp% DIVISOR;
            tmp = 0;
        }
    }
    return kk;
}
ll matrix::accessor() {
    return m_mat[0][0];
}