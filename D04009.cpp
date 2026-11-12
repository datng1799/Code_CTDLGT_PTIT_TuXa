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
        int par[1005];
        fill(&par[0], &par[0]+1005, -1);
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
        qu.push(start);
        checked[start] = true;
        par[start] = 0;
        int dem = 0;
        while (!qu.empty()) {
            int uu = qu.front();
            qu.pop();
            //cout << uu <<endl;
            for (int i = 0; i<vertical[uu].size(); i++) {
                int vv = vertical[uu][i];
                if (checked[vv] == false) {
                    checked[vv] = true;
                    qu.push(vv);
                    par[vv] = uu;
                }
            }
        }
        //-------------------------------//
        stack <int> st;
        for (int i = 1; i<=V; i++)
            if (i!=start) {
            while (!st.empty()) st.pop();
            int i2 = i;
            bool flag = true;
            while (i2>0) {
                st.push(i2);
                i2 = par[i2];
                if (i2<0) {
                    flag = false;
                    break;
                }
                if (i2==0) break;
            }
            if (!flag) cout << "No path" <<endl; else
            {
                while (!st.empty()) {
                    cout << st.top() <<" ";
                    st.pop();
                    if (st.empty()) break;
                    }
                cout <<endl;
            }
        }
    }
}
