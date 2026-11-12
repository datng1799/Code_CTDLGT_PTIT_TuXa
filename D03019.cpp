#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

const int dirX[4]  = {1, 0, 0, -1};
const int dirY[4] = {0, 1, -1, 0};
queue <pair <int, int> > qu;
int d[105][105];
int a[105][105];
char s[105];
int n;
int T;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int  i = 0; i<n; i++) {
            char s[105];
            scanf("%s", &s);
            for (int j = 0; j<n; j++) {
                if (s[j] == '.') a[i][j] = 1;
                else a[i][j] = 0;
                d[i][j] = 1000000007;
            }
        }
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        while (!qu.empty()) qu.pop();
        int res = 1000000007;
        qu.push({x1, y1});
        d[x1][y1] = 0;
        while (!qu.empty()) {
            int xx = qu.front().first;
            int yy = qu.front().second;
            qu.pop();
            if (xx==x2 &yy == y2) {
                res = min(res, d[xx][yy]);
            } else {
                //--- sang phai ---/
                for (int newxx = xx+1; newxx<n; newxx++) {
                    if (a[newxx][yy] == 0) break;
                    if (d[newxx][yy]>d[xx][yy]+1) {
                        d[newxx][yy] = d[xx][yy]+1;
                        qu.push({newxx, yy});
                    }
                }
                //--- sang trai --//
                for (int newxx = xx-1; newxx>=0; newxx--) {
                    if (a[newxx][yy] == 0) break;
                    if (d[newxx][yy]>d[xx][yy]+1) {
                        d[newxx][yy] = d[xx][yy]+1;
                        qu.push({newxx, yy});
                    }
                }
                //--- di len ---/
                for (int newyy = yy+1; newyy<n; newyy++) {
                    if (a[xx][newyy] == 0) break;
                    if (d[xx][newyy]>d[xx][yy]+1) {
                        d[xx][newyy] = d[xx][yy]+1;
                        qu.push({xx, newyy});
                    }
                }
                //-- di xuong --//
                 for (int newyy = yy-1; newyy>=0; newyy--) {
                    if (a[xx][newyy] == 0) break;
                    if (d[xx][newyy]>d[xx][yy]+1) {
                        d[xx][newyy] = d[xx][yy]+1;
                        qu.push({xx, newyy});
                    }
                }
            }
        }
        if (res == 1000000007) printf("0\n");
        else printf("%d\n",res);
    }
}
