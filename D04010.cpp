#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1005];
bool checkDfs[1005];
bool checkBfs[1005];
string resDfs[1005];
string resBfs[1005];
int N, M;


void Dfs(int u) {
    checkDfs[u] = true;
    for (auto v:adj[u]) {
        if (checkDfs[v]) continue;
        string v_string = to_string(v);
        resDfs[v] = resDfs[u]+" "+v_string;
        Dfs(v);
    }
}
void Bfs(int u) {
    queue <int> qu;
    for (int i = 1; i<=N; i++) resBfs[i].clear();
    qu.push(u);
    resBfs[u] = to_string(u);
    memset(checkBfs, 0 , sizeof(checkBfs));
    checkBfs[u] = true;
    while (!qu.empty()) {
        int uu = qu.front();
        qu.pop();
        for (auto v:adj[uu]) {
            if (v == 1) {
                string v_string = to_string(v);
                resBfs[v] = resBfs[uu]+" "+v_string;
                return;
            }
            if (checkBfs[v]) continue;
            string v_string = to_string(v);
            resBfs[v] = resBfs[uu]+" "+v_string;
            checkBfs[v] = true;
            qu.push(v);
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    resDfs[1] = "1";
    //-----------------------//
    Dfs(1);
    for (int i = 2; i<=N; i++) {
        if (checkDfs[i]) {
            cout << resDfs[i] << endl;
            Bfs(i);
            cout << resBfs[1] << endl;
        } else{
            cout << "-1" <<endl;
            cout << "-1" <<endl;
        }
    }
}
