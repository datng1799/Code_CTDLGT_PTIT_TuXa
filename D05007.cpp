#include <bits/stdc++.h>

using namespace std;

int Test, Edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Test;

    while  (Test --) {
        set <int> nodes;
        int  u, v; char c;
        cin >> Edge;
        for (int i = 0; i<Edge; i++) {
            cin >> u >> v >> c;
            nodes.insert(u);
            nodes.insert(v);
        }

        for (auto value:nodes)
            cout << value <<" ";
        cout << endl;
    }
}
