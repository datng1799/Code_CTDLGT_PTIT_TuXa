#include <bits/stdc++.h>

using namespace std;


int Edge;
int rank_node[10005];
bool is_children[10005];
int num_child[10005];
int L[10005], R[10005];
set <int> nodes;
int Leaf[10005];
int Test, root;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test --) {
        memset(rank_node, 0, sizeof(rank_node));
        memset(is_children, 0, sizeof(is_children));
        memset(num_child, 0, sizeof(num_child));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        memset(Leaf, 0, sizeof(Leaf));
        nodes.clear();

        bool OK = true;
        int u, v;
        char c;
        cin >> Edge;
        //---------------//
        for (int  i = 0; i<Edge; i++) {
            cin >> u >> v >> c;
            is_children[v] = true;
            num_child[u]++;
            if (c == 'L') L[u] = v; else R[u] = v;
            nodes.insert(u);
            nodes.insert(v);
        }
        //--------------//
        // ---- kiem tra node co du 2 con khong ---//
        for (auto v:nodes) {
            if (num_child[v] == 1) {
                OK = false;
                break;
            }
        }
        /*
        for (auto v:nodes) {
            cout << v << " " << num_child[v] << endl;
        }
        */

        if (!OK) {
            cout << "No" <<endl;
            continue;
        }
        // --- tim root ---//
        for (auto v:nodes) {
            if (!is_children[v]) {
                root = v;
            }
        }

        queue <int> qu;
        qu.push(root);
        rank_node[root] = 0;
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            if (num_child[u] == 0) {
                Leaf[rank_node[u]]++;
                continue;
            }
            rank_node[L[u]] = rank_node[R[u]] = rank_node[u]+1;
            qu.push(L[u]);
            qu.push(R[u]);
        }
        for (auto v:nodes)
            if (num_child[v] == 0) {
                if (Leaf[rank_node[v]]!=(int) pow(2, rank_node[v])) {
                    OK = false; break;
                }
            }
        if (OK) cout << "Yes" <<endl;
        else cout <<"No" <<endl;

        /*
        for (auto v:nodes)
            if (num_child[v] == 0) {
                cout << v <<" " << Leaf[rank_node[v]] << endl;
            } */
    }
}
