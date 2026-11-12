#include <bits/stdc++.h>

using namespace std;

int T, V;
vector <int> adj[1005];
bool visited[1005];
bool isTree;

bool Dfs(int u, int parent) {
    visited[u] = true;
    for (auto v:adj[u]){
        if (v == parent) continue;

        if (visited[v]) return false;
        if (!Dfs(v, u)) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> V;
        isTree = true;
        for (int i = 1; i<=V; i++) {
            visited[i] = false;
            adj[i].clear();
        }
        for (int i = 1; i<=V-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i= 1; i<=V && isTree; i++)
            if (!visited[i]) isTree = Dfs(i, 0);

        cout << (isTree? "YES":"NO") <<"\n";
    }
}
