#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, int> ii;

int Test;
int N, M, u_start;
vector <ii> adj[100005];
ll d[100005];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> Test;
    while (Test -- ) {
        cin >> N >> M >> u_start;
        for (int i = 1; i<=N; i++) {
                d[i] = LLONG_MAX;
                adj[i].clear();
        }
        d[u_start] = 0;

        for (int i = 0; i<M; i++) {
            int u, v;
            ll dist;
            cin >> u >> v >> dist;
            adj[u].push_back({dist, v});
            adj[v].push_back({dist, u});
        }

        priority_queue <ii, vector <ii>, greater <ii> > pq;
        pq.push({d[u_start],u_start});
        while (!pq.empty()) {
            ii pair_u = pq.top();
            int u = pair_u.second;
            ll du  = pair_u.first;
            pq.pop();
            for (auto vv: adj[u]) {
                int distt = vv.first;
                int v = vv.second;
                if (d[v]>du+distt) {
                    d[v] = du+distt;
                    pq.push({d[v],v});
                }
            }
        }
        for (int i = 1; i<=N; i++) cout << d[i] << " ";
        cout << endl;
    }
}
