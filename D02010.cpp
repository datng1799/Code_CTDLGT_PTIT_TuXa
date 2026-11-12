#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007;
int T;
int N, K;
long long f[100005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        memset(f, 0 , sizeof(f));
        f[0] = 1;
        f[1] = 1;
        cin >> N >> K;
        for (int i = 2; i<=N; i++)
            for (int j = 1; j<=min(K,i); j++){
                f[i] = (f[i] + f[i-j])%mod;
        }
        cout << f[N] <<endl;
    }
}
