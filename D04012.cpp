#include <bits/stdc++.h>

using namespace std;

int Test;
int n ,m;
vector <int> adj[100005];
int label[100005];
int countt;
int order = 0, res;
queue <int> qu;

void bfs(int uu) {
    label[uu] = order;
    qu.push(uu);
    while (!qu.empty()) {
        int u  = qu.front();
        qu.pop();
        for (auto v:adj[u]) {
            if (label[v] == 0) {
                label[v] = order;
                countt++;
                qu.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> Test;
    // Scan all Test
    while (Test--) {
        res = 0; // so thanh phan lon nhat
        order = 0; // nhan dan
        // nhap so dinh va canh cua do thi
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i<m; i++) {
            int  u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(label, 0 , sizeof(label));
        while (!qu.empty()) qu.pop();
        countt = 0;

        for (int i = 1; i<=n; i++)
            if (label[i] == 0) {
                order++;
                countt = 1;
                bfs(i);
                res = max(res, countt);
        }
        res = max(res, countt);
        cout << res << endl;
    }
}
