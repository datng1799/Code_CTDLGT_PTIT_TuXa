#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;
int N, M, Q;
long long distt[105][105];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i<=N; i++)
        for (int j = i; j<=N; j++)
            if (i == j) distt[i][j] = distt[j][i] = 0;
                else distt[i][j] = distt[j][i] = INF;

    for (int i = 0; i<M; i++) {
        int u, v;
        long long d;
        cin >> u >> v >> d;
        distt[u][v] = distt[v][u] = d;
    }

    for (int k = 1; k<=N; k++)
        for (int i = 1; i<=N; i++)
            for (int j = 1; j<=N; j++) {
                if (distt[i][k] == INF) continue;
                if (distt[i][k]+distt[k][j]<distt[i][j])
                    distt[i][j] = distt[i][k]+distt[k][j];
            }

    cin >> Q;
    while (Q--) {
        int uu, vv;
        cin >>  uu >> vv;
        cout << distt[uu][vv] << endl;
    }
}
