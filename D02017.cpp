#include <bits/stdc++.h>
using namespace std;

vector <double> a;
vector <double> b;

int f[505];
int T;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        fill(&f[0], &f[0]+N+1, -1);
        f[0] = 0;
        a.resize(N+1);
        b.resize(N+1);
        a[0] = -1000000007.0;
        b[0] = 1000000007.0;
        for (int i = 1; i<=N; i++) cin >> a[i] >> b[i];

        //---------------//

        for (int i = 1; i<=N; i++)
            for (int j = 0; j<i; j++) {
                if ((a[i]-a[j]>0.001)&&(b[j]-b[i]>0.001))
                    if (f[j]!=-1) f[i] = max(f[i], f[j]+1);
        }

        int res = 0;
        for (int i = 1; i<=N; i++) res = max(res, f[i]);
        cout << res <<endl;
    }
}
