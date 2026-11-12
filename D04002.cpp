#include <bits/stdc++.h>
using namespace std;

int T;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >>  T;
    while (T--) {
        //--- cac thanh phan ----//
        vector <int> vertical[1005];
        bool checked[1005] = {false};
        int V, E, start;

        //-----------------------//

        //----- nhap thong tin ----//
        cin >> V >> E >> start;
        for (int i = 1; i<=E; i++) {
            int u, v;
            cin >> u >> v;
            vertical[u].push_back(v);
            vertical[v].push_back(u);
        }
        //-------------------------//
        //-------duyet cac dinh ---//
        queue <int> qu;
        vector <int> v;

        qu.push(start);
        checked[start] = true;
        int dem = 0;
        while (!qu.empty()) {
            int uu = qu.front();
            qu.pop();
            v.push_back(uu);
            //cout << uu <<endl;
            for (int i = 0; i<vertical[uu].size(); i++) {
                int vv = vertical[uu][i];
                if (checked[vv]==false) {
                    checked[vv] = true;
                    qu.push(vv);
                }
            }
        }
        //-------------------------------//
        for (int i = 0; i<v.size();i++) cout << v[i] <<" ";
        cout << endl;
    }
}
