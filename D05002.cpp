#include <bits/stdc++.h>
using namespace std;

int T;
int L[10005], R[10005];
bool isChildren[10005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {

        int n;
        cin >> n;

        //-------------------//
        vector <int> Node;

        for (int i = 0; i<n; i++) {
            int u , v;
            char ch;
            cin >> u >> v >> ch;
            //----------------//
            if (ch == 'L') L[u] = v; else R[u] = v;

            isChildren[v] = true;
            Node.push_back(u);
            Node.push_back(v);
        }
        //---- tim goc ------//
        int root = 0;
        for (int node: Node)
            if (isChildren[node] == false) {
                root = node;
                break;
        }
        //------------------//
        queue <int> q;
        if (root!=0) q.push(root);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current <<" ";

            if (L[current]!=0) q.push(L[current]);
            if (R[current]!=0) q.push(R[current]);
        }
        cout << endl;

        for (int node: Node) {
            L[node] = R[node] = 0;
            isChildren[node] = false;
        }
    }

}
