#include <iostream>

using namespace std;

int N, T;
long long d[1000005][2];
long long a[1000005];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i<=N; i++) {
            cin >> a[i];
        }
        d[1][0] = 0;
        d[1][1] = a[1];
        d[2][0] = a[1];
        d[2][1] = a[2];

        for (int i=3; i<=N; i++) {
            d[i][0] = max (d[i-1][1], d[i-1][0]);
            d[i][1] = max (d[i-1][0]+a[i], d[i-1][1]);
        }

        int res = max(d[N][1], d[N][0]);
        cout << res <<endl;
    }
}
