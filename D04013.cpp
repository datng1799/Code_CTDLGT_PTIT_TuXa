#include <bits/stdc++.h>
using namespace std;

int Test;
int n, m, order;
vector <int> adj[100005];
int  label[100005], countt[100005];
queue <int> qu;


void bfs(int uu) {
    label[uu] = order;
    countt[order]++;
    qu.push(uu);

    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();

        for (auto v:adj[u])
            if (label[v] == 0){
                label[v] = order;
                countt[order]++;
                qu.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;

    while (Test--) {
        cin >> n >> m;
        for (int i = 1; i<=n; i++) adj[i].clear();
        memset(countt, 0, sizeof(countt));
        memset(label, 0, sizeof(label));

        for (int i=0 ;i<m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1; i<=n; i++)
            if (label[i] == 0){
                order++;
                bfs(i);
            }
        bool ok = true;
        for (int i = 1; i<=n; i++)
        if (adj[i].size() != countt[label[i]]-1) {
            ok = false; break;
        }

        cout << (ok? "YES\n":"NO\n");
    }


}
