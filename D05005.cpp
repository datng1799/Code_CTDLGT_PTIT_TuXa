#include <bits/stdc++.h>

using namespace std;

struct Node {
    int parent = 0;
    int L = 0;
    int R = 0;
};

Node nodes1[10005];
Node nodes2[10005];
set <int> node_filter1, node_filter2;
int Test, Edge1, Edge2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test --) {
        int u, v; char c;
        cin >> Edge1;
        for (int i = 0; i<Edge1; i++) {
            cin >> u >> v >> c;
            node_filter1.insert(u);
            node_filter1.insert(v);
            nodes1[v].parent = u;
            if (c == 'L') nodes1[v].L = 1;
                else nodes1[v].R = 1;
        }

        cin >> Edge2;
        for (int i = 0; i<Edge2; i++) {
            cin >> u >> v >> c;
            node_filter2.insert(u);
            node_filter2.insert(v);
            nodes2[v].parent = u;
            if (c == 'L') nodes2[v].L = 1;
                else nodes2[v].R = 1;
        }

        bool Ok = true;
        if (node_filter1.size()!=node_filter2.size()) {
            Ok = false;
        }
        if (!Ok) {
            cout << "0" << endl;
            continue;
        }
        for (auto it: node_filter2)
            if (!node_filter1.count(it)) {
                 Ok = false;
                 break;
            } else if (nodes1[it].parent!=nodes2[it].parent||
                    nodes1[it].L!=nodes2[it].L||
                    nodes1[it].R!=nodes2[it].R) {
                    Ok = false;
                    break;
            }
        if (Ok) cout << "1" <<endl;
        else cout << "0" <<endl;
        node_filter1.clear();
        node_filter2.clear();
    }
}
