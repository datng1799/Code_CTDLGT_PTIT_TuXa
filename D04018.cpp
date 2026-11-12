#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;
typedef pair <long long, ii> iil;

const int INF = 3e6;
const int addX[4] = {-1, 0 , 0, 1};
const int addY[4] = {0, -1 , 1, 0};

int Test, N, M;
int a[505][505];
int d[505][505];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test -- ) {
        cin >> N >> M;
        for (int i = 1; i<=N; i++)
            for (int j = 1; j<=M; j++) {
                cin >> a[i][j];
                d[i][j] = INF;
            }
        d[1][1] = a[1][1];

        priority_queue <iil, vector <iil>, greater <iil> > pq;
        pq.push({d[1][1], {1,1}});
        while (!pq.empty()) {
            int u_i = pq.top().second.first;
            int v_i = pq.top().second.second;
            long long dist_uv = pq.top().first;
            pq.pop();
            for (int tt = 0; tt <4; tt++) {
                int new_u  = u_i + addX[tt];
                int new_v  = v_i + addY[tt];
                if (new_u == 0 || new_u >N || new_v == 0 || new_v >M) continue;
                if (d[new_u][new_v] > dist_uv + a[new_u][new_v]) {
                    d[new_u][new_v] = dist_uv + a[new_u][new_v];
                    pq.push({ d[new_u][new_v], {new_u, new_v} });
                }
            }
        }
        cout << d[N][M] <<endl;
    }
}
