#include <bits/stdc++.h>

using namespace std;


int V, E;
int orderGroup = 0;
vector <int> quantityElement;
vector <int> adj[100005];
int visited[100005] = {false};
int Count;

void Dfs(int u) {
    Count++;
    visited[u] = true;
    for (auto v:adj[u]) {
        if (!visited[v]) Dfs(v);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >>  V >> E;
    for (int i = 0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i<=V; i++)
        if (!visited[i]) {
            Count = 0;
            Dfs(i);
            quantityElement.push_back(Count);
    }
    int res = 0;
    if (quantityElement.size()>1)
        for (int  i = 1; i<quantityElement.size(); i++) {
        res = max(res, quantityElement[i]);
    }

    cout << res + quantityElement[0];
}
