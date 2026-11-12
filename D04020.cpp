#include <bits/stdc++.h>

using namespace std;
typedef pair<long long, int> ii;
const long long INF = 1e15;

int N, M;
long long dist[100005];
int cnt[100005];
vector <ii> adj[100005];
priority_queue <ii, vector <ii>, greater <ii> > pq;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1 ;i<=N; i++) {
        dist[i] = INF;
        cnt[i] = 1;
    }
    for (int i = 0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        long long du = pq.top().first;
        pq.pop();
        for (auto vv:adj[u]) {
            long long uv = vv.first;
            int v = vv.second;
            if (dist[v]>du+uv) {
                dist[v] = du+uv;
                cnt[v] = cnt[u];
                pq.push({dist[v], v});
            } else if (dist[v]== du+uv){
                cnt[v] += cnt[u];
            }
        }
    }
    cout << dist[N] <<" "<<cnt[N]<<endl;
}
