#include <bits/stdc++.h>
using namespace std;


struct Point{
    int X;
    int Y;
};

Point p[100005];
int T, N;

int d[100005];
bool cnt(Point &a, Point &b) {
    if (a.Y==b.Y) return(a.X<b.X);
    return (a.Y<b.Y);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i<=N; i++) {
            cin >> p[i].X >> p[i].Y;
        }
        sort(p+1, p+N+1, cnt);
        int lastEnd = 0;
        int res = 0;
        for (int i=1; i<=N; i++) {
            if (p[i].X>=lastEnd) {
                res++;
                lastEnd = p[i].Y;
            }
        }
        cout << res <<endl;
    }
}
