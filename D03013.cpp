#include <bits/stdc++.h>

using namespace std;

queue <string> q1;
queue <string> q2;
int f[16], sum[16];
int T;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    f[1] = 2;
    for (int i = 2; i<=15; i++) f[i] = f[i-1]*2;
    sum[1] = 2;
    for (int i = 2; i<=15; i++) sum[i] = sum[i-1]+f[i];
    cin >> T;
    while (T--) {
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
        int n;
        string s;
        int dem = 0;
        cin >> n;
        cout << sum[n] << endl;
        q1.push("6"); q1.push("8");
        for (int i = 0; i<n; i++) {
            while (!q1.empty()) {
                string s = q1.front();
                dem++;
                q2.push(s+"6");
                q2.push(s+"8");
                cout << s <<" ";
                q1.pop();
            }
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        cout << endl;
    }
}
