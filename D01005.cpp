#include <bits/stdc++.h>
using namespace std;

int k, n;
int T;
int a[15];
int C[15][15];

void init() {
    C[0][0] = 0;
    C[0][1] = 1;
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= i+1; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    a[0] = 0;

   /* for (int i = 0; i<15; i++) {
        cout <<i<<": ";
        for (int j = 1; j <= i+1; j++) cout <<C[i][j] <<" ";
        cout <<endl;
    }*/
    cin >> T;
    while (T--) {
        cin >> n >> k;
        int res = 1;
            for (int i = 1; i <=k; i++) {
                cin >> a[i];
                for (int delta = a[i-1]+1; delta <=a[i]-1; delta++)
                    res += C[n - delta][k - i + 1];

            }
        cout << res << endl;
    }
}
