#include <bits/stdc++.h>
using namespace std;

int T;
int f[1005][1005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> T;
    while (T--) {
        string S1, S2;
        cin >> S1 >> S2;

        int l1 = S1.size(), l2 = S2.size();

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++)
                if (S1[i-1] == S2[j-1]) {
                f[i][j] = f[i-1][j-1]+1;
            } else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }

        cout << f[l1][l2] <<"\n";
    }
}
