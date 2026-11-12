#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1005];
int Order = 0;
int  T,V,E;
int Group[1005];

void Dfs(int u) {
    Group[u]= Order;
    for (int v: adj[u]) {
        if (Group[v] == 0) Dfs(v);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> V >> E;
        for (int i = 1; i<=V; i++)  {
                adj[i].clear();
                Group[i] = 0;
        }
        for (int i = 1; i<=E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        Order = 0;
        for (int i = 1; i<=V; i++)
            if (Group[i] == 0) {
                Order ++;
                Dfs(i);
            }
        //--------------------------//
        cout << Order << endl;
    }
}
