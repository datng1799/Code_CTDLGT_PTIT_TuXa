#include <bits/stdc++.h>

using namespace std;

int T, N;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        priority_queue <long long, vector <long long>, greater<long long> > pq;
        cin >> N;
        int inp;
        for (int i = 1; i<=N; i++) {
            cin >> inp;
            pq.push(inp);
        }

        long long res = 0;

        while (!pq.empty()){
            long long s1 = pq.top();
            pq.pop();
            if (pq.empty()) break;
            long long s2 = pq.top();
            pq.pop();

            res = res + s1 + s2;
            pq.push(s1+s2);
        }

        cout << res << endl;
    }
}
