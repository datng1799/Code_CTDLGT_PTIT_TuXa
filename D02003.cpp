#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int T;
long long bigPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b%2==1) res = (res*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //----------//
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << bigPow(n, k) << endl;
    }
    //---------//
}
