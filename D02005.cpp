#include <bits/stdc++.h>

using namespace std;
const int money[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
const int maxx = 1000000007;

int d[100005];
int T;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    memset(d, 1000000007, sizeof(d));
    d[0] = 0;
    for (int i = 1; i<=100000; i++)
        for (int j = 9; j>=0; j--) {
            if (i>=money[j]) {
                if (d[i - money[j]]!=maxx) d[i] = min(d[i], d[i-money[j]] + 1);
            }

        }
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << d[N] << endl;
    }
}
