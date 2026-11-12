#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull N;
int T;


int  bfsSolve(ull n) {
    if (n==1) return 0;
    unordered_map<ull, int> dist;
    queue<ull> q;
    dist[N] = 0;
    q.push(N);
    while (!q.empty()) {
        ull u = q.front(); q.pop();
        int d = dist[u];

        // phep bien doi a
        ull v1 = u - 1;
        if (v1>=1 && dist.count(v1)==0) {
            if (v1 == 1) return(d+1);
            dist[v1]  = d+1;
            q.push(v1);
        }

        // phep bien doi b
        for (ull dd = 2; dd*dd <=u; dd++){
            if (u%dd == 0) {
                ull v = u/dd;
                if (dist.count(v) == 0) {
                    dist[v] = d+1;
                    q.push(v);
                }
            }
        }
    }
    return (-1);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        cout << bfsSolve(N) << endl;
    }
}
