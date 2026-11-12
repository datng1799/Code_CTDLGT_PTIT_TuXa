#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> T;
    while (T--) {
        int N;
        string s;
        cin >> N >> s;
        N = s.size();

        vector < vector <int> > f(N+1, vector <int> (N+1, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if ( (s[i-1] == s[j-1]) && (i!=j) ) {
                    f[i][j] = f[i-1][j-1]+1;
                } else {
                    f[i][j] = max(f[i-1][j], f[i][j-1]);
                }
            }
        }

        cout << f[N][N] <<"\n";
    }

    return 0;
}
