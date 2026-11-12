#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int mod = 1000000007;

int d[9][9], T;
queue <ii> q;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        while (!q.empty()) q.pop();
        fill(&d[0][0], &d[0][0]+9*9, mod);
        string xy;
        string uv;
        cin >> xy;
        cin >> uv;
        int sx = int(xy[0] - 'a')+1;
        int sy = int(xy[1] - '0');

        int tx = int(uv[0] - 'a')+1;
        int ty = int(uv[1] - '0');
        //cout << sx << " " <<sy <<endl;
        //cout << tx << " " <<ty <<endl;
        q.push({sx,sy}); d[sx][sy] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // sang phai
            int x1 = x + 2;
            int y1 = y + 1;
            if (x1>0 && x1<9 && y1>0 && y1<9) {
                if (d[x1][y1]>d[x][y]+1) {
                    d[x1][y1] = d[x][y]+1;
                    q.push({x1,y1});
                }
            }

            int x2 = x + 2;
            int y2 = y - 1;
            if (x2>0 && x2<9 && y2>0 && y2<9){
                if (d[x2][y2]>d[x][y]+1) {
                    d[x2][y2] = d[x][y]+1;
                    q.push({x2,y2});
                }
            }
            // len tren
            int x3 = x + 1;
            int y3 = y + 2;
            if (x3>0 && x3<9 && y3>0 && y3<9){
                if (d[x3][y3]>d[x][y]+1) {
                    d[x3][y3] = d[x][y]+1;
                    q.push({x3,y3});
                }
            }

            int x4 = x - 1;
            int y4 = y + 2;
            if (x4>0 && x4<9 && y4>0 && y4<9){
                if (d[x4][y4]>d[x][y]+1) {
                    d[x4][y4] = d[x][y]+1;
                    q.push({x4,y4});
                }
            }

            // sang trai
            int x5 = x - 2;
            int y5 = y + 1;
            if (x5>0 && x5<9 && y5>0 && y5<9){
                if (d[x5][y5]>d[x][y]+1) {
                    d[x5][y5] = d[x][y]+1;
                    q.push({x5,y5});
                }
            }

            int x6 = x - 2;
            int y6 = y - 1;
            if (x6>0 && x6<9 && y6>0 && y6<9){
                if (d[x6][y6]>d[x][y]+1) {
                    d[x6][y6] = d[x][y]+1;
                    q.push({x6,y6});
                }
            }
            // xuong duoi
            int x7 = x + 1;
            int y7 = y - 2;
            if (x7>0 && x7<9 && y7>0 && y7<9){
                if (d[x7][y7]>d[x][y]+1) {
                    d[x7][y7] = d[x][y]+1;
                    q.push({x7,y7});
                }
            }

            int x8 = x - 1;
            int y8 = y - 2;
            if (x8>0 && x8<9 && y8>0 && y8<9){
                if (d[x8][y8]>d[x][y]+1) {
                    d[x8][y8] = d[x][y]+1;
                    q.push({x8,y8});
                }
            }
        }
        cout << d[tx][ty] <<endl;
    }
}
