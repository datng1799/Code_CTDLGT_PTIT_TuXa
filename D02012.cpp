#include <bits/stdc++.h>
using namespace std;

int we[5005];
int mo[5005];
long long f[5005][5005];
long long res = 0;
int N, M;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i<=N; i++) {
        cin >> we[i] >> mo[i];
    }
    long long res = 0;
    memset(f, -1, sizeof(f));
    for (int i = 1; i<=N; i++) {
            f[i][0] = 0;
    }
    for (int i = 1; i<=N; i++) {
        for (int j = 1; j<=M; j++) {
            f[i][j] = max(f[i-1][j], f[i][j]);
            if (j-we[i]>=0) {
                f[i][j] = max(f[i][j], f[i-1][j-we[i]]+1LL*mo[i]);
                res = max(res, f[i][j]);
            }
        }
    }
    cout << res << endl;
}
