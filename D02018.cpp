#include <bits/stdc++.h>
using namespace std;

const int maxN = 905;
const int maxS = 10005;
const int mod = 1e9+7;

int T;
int f[maxN][maxS];

void init() {

    fill(&f[0][0], &f[0][0]+maxN * maxS, mod);
    f[0][0] = 0;
    for (int i = 1; i <= 901; i++)
        for (int j = 1; j<=10001; j++)
            for (int k = 1; k<=9; k++)
                if (i>=k && j>=k*k) {
                if (f[i-k][j-k*k]!=mod) f[i][j] = min(f[i][j], f[i-k][j-k*k]+1);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    cin >> T;
    while (T--) {
        int N, S;
        cin >> N >> S;
        if (f[N][S] == mod) {
            cout <<"-1";
            cout <<endl;
        } else {
            vector <int> a;
            while (f[N][S]!=0) {
                for (int i = 1; i<=9; i++) {
                    if (i>N||i*i>S) break;
                    if (f[N-i][S-i*i]== f[N][S]-1) {
                        a.push_back(i);
                        N -=i;
                        S -=i*i;
                        break;
                    }
                }
            }
            for (int aa:a) cout <<aa;
            cout <<endl;
        }


    }
}
