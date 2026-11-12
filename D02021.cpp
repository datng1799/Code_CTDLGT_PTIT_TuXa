#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int a[105];
int N;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int buoc = 0;
    cin >> N;
    for (int i = 1; i<=N; i++) cin >> a[i];
    for (int i = 1; i<=N-1; i++) {
        int minn = mod;
        int pos = 0;
        for (int j = i+1; j<=N; j++) {
            if (a[j]<minn) {
                minn = a[j];
                pos = j;
            }
        }
        buoc++;
        if (a[pos]<a[i]) {
            int tg = a[i];
            a[i] = a[pos];
            a[pos] = tg;
        }
        printf("Buoc %d: ", buoc);
        for (int k = 1; k <=N; k ++) printf("%d ", a[k]);
        printf("\n");
    }
}
