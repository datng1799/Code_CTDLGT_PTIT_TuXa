#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1005];
int low[1005], num[1005];
int timeDfs;
bool Joint[1005];
int T, E, V;

void Dfs(int u, int parent) {
    low[u] = num[u] = ++timeDfs;
    int numChilds = 0;
    for (int i = 0; i<adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == parent) continue;
        if (num[v] == 0) {
            Dfs(v, u);
            low[u] = min(low[u], low[v]);
            numChilds ++;
            if (parent != 0 && low[v]>=num[u]) Joint[u] = true;
        } else low[u] = min(low[u], num[v]);
    }
    if (parent == 0 && numChilds >=2) Joint[u] = true;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        timeDfs = 0;
        memset(Joint, false, sizeof(Joint));
        cin >> V >> E;
        for (int i = 1; i<=V; i++) {
            adj[i].clear();
            low[i] = num[i] = 0;
        }
        for (int i = 0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i<=V; i++) {
            if (num[i] == 0) Dfs(i, 0);
        }

      /*  for (int i = 1; i<=V; i++) {
            cout << i << " low[" <<i<<"] = " <<low[i]
                << "num[" << i <<"]= " << num[i] <<endl;
        } */

        for (int i = 1; i<=V; i++) if (Joint[i]) cout << i <<" ";
        cout << endl;
    }
}
