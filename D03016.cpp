#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int mod =1000000007;

int a[1005][1005];
queue <ii> q;
int d[1005][1005];
int T;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        int res = mod;
        while (!q.empty()) q.pop();
        int n, m;
        cin >> n >> m;
        fill(&d[0][0], &d[0][0]+1001*1001, mod);
        for (int i = 1; i<=n; i++)
            for (int j = 1; j<=m; j++) cin >> a[i][j];

        q.push({1,1}); d[1][1] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int xx = x+a[x][y];
            int yy = y+a[x][y];
            //--------//
            if (xx>0&&xx<n+1) {
                if (d[xx][y]>d[x][y]+1) {
                    d[xx][y]=d[x][y]+1;
                    q.push({xx,y});
                }
            }
            //----------//
            if (yy>0&&yy<m+1) {
                if (d[x][yy]>d[x][y]+1) {
                    d[x][yy]=d[x][y]+1;
                    q.push({x,yy});
                }
            }
            //------------//
        }
        if (d[n][m] == mod) cout << "-1" <<endl;
        else cout << d[n][m] << endl;
    }
}
