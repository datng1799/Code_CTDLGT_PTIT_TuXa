#include <bits/stdc++.h>

using namespace std;
int d[20005], T;
const int mod = 1000000007;
queue <int> q1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        while (!q1.empty()) q1.pop();
        int res = mod;
        int s, t;
        cin >> s >> t;
        fill(&d[0], &d[0]+20005, mod);
        q1.push(s); d[s] = 0;
        while (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            if (val == t){
                res = min(res, d[val]);
            }
            if (val > t) {
                int val1 = val - 1;
                if (d[val1]>d[val]+1) {
                    d[val1] = d[val]+1;
                    q1.push(val1);
                }
            }
            if (val < t) {
                int val1 = val - 1;
                if (val1>0&&d[val1]>d[val]+1) {
                    d[val1] = d[val]+1;
                    q1.push(val1);
                }
                int val2 = val*2;
                 if (d[val2]>d[val]+1) {
                    d[val2] = d[val]+1;
                    q1.push(val2);
                }
            }
        }

        cout << res << endl;
    }
}
