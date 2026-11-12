#include <bits/stdc++.h>

using namespace std;

queue <int> qu;
vector <int> adj[100005];
bool check[100005];
int Test;
int N, M, U;
int countt = 0;

void DFS(int u, int parent) {
    //cout << u <<" " <<parent << endl;
    check[u] = true;
    for (auto v:adj[u]) {
        //if (v == parent) continue;
        if (check[v] == false) {
            qu.push(u);
            qu.push(v);
            countt++;
            DFS(v,u);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test--) {
        countt = 0;
        while (!qu.empty()) qu.pop();
        cin >> N >> M >> U;
        for (int i=1; i<=N; i++) check[i] = false;
        for (int i = 0; i<M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(U, 0);
        if (countt == N-1) {
            while (!qu.empty()) {
            cout <<qu.front() <<" "; qu.pop();
            cout <<qu.front() <<"\n"; qu.pop();
            }
        } else cout <<"-1\n";
        for (int i = 1; i<=N; i++) adj[i].clear();
    }
}
