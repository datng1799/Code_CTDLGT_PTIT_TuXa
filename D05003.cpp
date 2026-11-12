#include <bits/stdc++.h>

using namespace std;

int Edge;
bool is_Children[10005];
bool not_is_Leaf[10005];
int rank_node[10005];
int L[10005];
int R[10005];
vector <int> nodes;
vector <int> Leaf;
int Test, root;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;

    while (Test --) {
        int u, v; char c;
        memset(rank_node, 0 , sizeof(rank_node));
        memset(is_Children, 0 , sizeof(is_Children));
        memset(not_is_Leaf, 0 , sizeof(not_is_Leaf));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        nodes.clear();
        Leaf.clear();
        cin >> Edge;
        for (int  i = 0; i<Edge; i++) {
            cin >> u >> v >> c;
            not_is_Leaf[u] = true;
            is_Children[v] = true;
            if (c == 'L') L[u] = v; else R[u] = v;
            nodes.push_back(u);
            nodes.push_back(v);
        }
        // --- set root --- //
        for (auto v: nodes)
            if (!is_Children[v]) {
                root = v;
                break;
        }

        // ---------------- //

        rank_node[root] = 1;
        queue <int> qu;
        qu.push(root);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            if (!not_is_Leaf[u]) {
                Leaf.push_back(u);
                continue;
            } else {
                if (L[u]!=0) {qu.push(L[u]); rank_node[L[u]] = rank_node[u]+1;}
                if (R[u]!=0) {qu.push(R[u]); rank_node[R[u]] = rank_node[u]+1;}
            }
        }

        //----------------------------------//
        int OK = 1;
        if (Leaf[0] == root) {
            cout << 0 <<endl;
            continue;
        }
        for (int i = 1; i<Leaf.size(); i++)
            if (rank_node[Leaf[i]]!= rank_node[Leaf[i-1]]) {
                OK = 0;
                break;
            }
        cout << OK << endl;
    }
}
