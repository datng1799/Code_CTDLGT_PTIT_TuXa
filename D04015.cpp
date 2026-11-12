#include <bits/stdc++.h>

using namespace std;

int Test;
int N, M, U;
vector <int> adj[100005];
queue <int> inkq;
queue <int> bfsQ;
bool check[100005];
int countt;

void BFS() {
    while (!bfsQ.empty()) {
        int u = bfsQ.front();
        bfsQ.pop();
        for (auto v:adj[u]) {
            if (check[v]) continue;
            check[v] = true;
            bfsQ.push(v);
            inkq.push(u);
            inkq.push(v);
            countt ++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test--) {
        countt = 0;
        cin >> N >> M >> U;
        for (int i = 1; i<=N; i++) {
            check[i] = false;
            adj[i].clear();
        }
        for (int i=0; i<M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfsQ.push(U);
        check[U] = true;
        BFS();
        if (countt == N-1) {
            while (!inkq.empty()) {
                cout << inkq.front() <<" "; inkq.pop();
                cout << inkq.front() <<"\n"; inkq.pop();
            }
        } else {
            while (!inkq.empty()) inkq.pop();
            cout <<"-1\n";
        }
    }
}
