#include <bits/stdc++.h>

using namespace std;


int T;
vector  <int> adj[1005];
int low[1005], num[1005];
int  V, E;
int timeDfs;
vector <pair <int, int> > res;


void Dfs(int u, int parent) {
    low[u] = num[u] = ++timeDfs;

    for (auto v:adj[u]) {
        if (v == parent) continue;
        if (num[v] == 0) {
            Dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                res.push_back({min(u, v) , max(u, v)});
            }
        } else low[u] = min(low[u], num[v]);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> T;
    while (T--) {

        cin >>  V >> E;
        timeDfs = 0;
        res.clear();
        //---- lam sach du lieu --//
        for (int i = 1; i<=V; i++) {
            low[i] = num[i] = 0;
            adj[i].clear();
        }

        // --- nhap canh ---//
        for (int i = 0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i<=V; i++)
            if (num[i] == 0) Dfs(i, 0);

        sort(res.begin(), res.end());
        if (res.size() == 0) cout <<endl;
        else  {
            for (auto it:res) {
                cout << it.first <<" "<<it.second <<" ";
            }
            cout << endl;
        }
    }
}
