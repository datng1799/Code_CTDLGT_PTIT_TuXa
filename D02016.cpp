#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int T;
int f[10005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fill(&f[0], &f[0]+10001, mod);
    f[0] = 0;
    for (int i = 1; i<=10001; i++) {
        for (int j = 1; j*j<=i; j++) {
            if (f[i-j*j]!=mod) f[i] = min(f[i], f[i-j*j]+1);
        }
    }
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << f[N] <<"\n";
    }
}
