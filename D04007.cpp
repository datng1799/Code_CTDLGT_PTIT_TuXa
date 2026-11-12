#include <bits/stdc++.h>

using namespace std;

int V, E, T;
vector <int> adj[1005];
int low[1005], num[1005];
bool haveCircle = false;
int timeDfs = 0;

void Dfs(int u, int  parent) {
    low[u] = num[u] = ++timeDfs;
    for (int v:adj[u]) {
        if (v == parent) continue;
        if (num[v] == 0) {
            Dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
            haveCircle = true;
            break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        timeDfs = 0;
        cin >> V >> E;
        for (int i = 1; i<=V; i++) {
            low[i] = num[i] = 0;
            adj[i].clear();
        }

        for (int  i = 0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        haveCircle = false;
        for (int i = 1; i<=V; i++) {
            if (num[i] == 0) Dfs(i, 0);
            if (haveCircle) break;
        }

        if (haveCircle) cout << "YES" <<endl;
        else cout << "NO" <<endl;
    }
}
