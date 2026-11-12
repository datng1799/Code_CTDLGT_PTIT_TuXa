#include <bits/stdc++.h>

using namespace std;

int parent[1005];
vector <int> adj[1005];
queue <int> q;
int T;
int main()
{
    cin >> T;
    while (T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        for (int i = 1; i<=V; i++) adj[i].clear();
        for (int i = 0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i<=V; i++) parent[i] = -1;
        while (!q.empty()) q.pop();
        parent[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v:adj[u]) {
                if (parent[u]!=v&&parent[v]==-1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        stack <int> res;
        if (parent[t] == -1) {
            cout << -1 << endl;
        } else {
            while (t!=0) {
            res.push(t);
            t = parent[t];
        }
            while (!res.empty()) {
                cout << res.top()<<" ";
                res.pop();
            }
            cout << endl;
        }

    }
}
