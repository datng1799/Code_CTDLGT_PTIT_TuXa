#include <bits/stdc++.h>

using namespace std;


unordered_map <string, int> dist;
queue <string> q;
int T;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        dist.clear();
        while (!q.empty()) q.pop();
        string st1 = "";
        string st2 = "";
        char c;
        for (int i = 1; i<=6; i++) {
            cin >> c;
            st1+=c;
        }
        for (int i = 1; i<=6; i++) {
            cin >> c;
            st2+=c;
        }
        //-------------------------//
        //cout << st1 << endl;
        //cout << st2 << endl;
        q.push(st1); dist[st1] = 0;
        while (!q.empty()) {
            string s = q.front();
            int d = dist[s];
            q.pop();
            string s1 = "";
            string s2 = "";
            s1 = s1+s[3]+s[0]+s[2]+s[4]+s[1]+s[5];
            s2 = s2+s[0]+s[4]+s[1]+s[3]+s[5]+s[2];

            if (dist.count(s1)==0) {
                dist[s1] = dist[s]+1;
                q.push(s1);
            } else if (dist[s1]>dist[s]+1) {
                dist[s1] = dist[s]+1;
                q.push(s1);
            }

            if (dist.count(s2)==0) {
                dist[s2] = dist[s]+1;
                q.push(s2);
            } else if (dist[s2]>dist[s]+1) {
                dist[s2] = dist[s]+1;
                q.push(s2);
            }
        }
        if (dist.count(st2)!=0) cout << dist[st2] << endl;
        else cout << 0 <<endl;
    }
}
