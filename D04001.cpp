#include <bits/stdc++.h>

using namespace std;

unordered_map <char, long long> mp;
priority_queue <long long> pq;

int T;
int main()
{
    cin >> T;
    while (T--) {
        mp.clear();
        long long res = 0;
        int k;
        string s;
        cin >> k;
        cin >> s;
        for (char c: s) mp[c]++;
        for (auto it = mp.begin(); it!=mp.end(); it++) {
            long long val = it->second;
            if (val!=0) pq.push(val);
        }
        while (k!=0) {
            if (pq.empty()) break;
            long long v = pq.top();
            pq.pop();
            v = v-1;
            k--;
            if (v>0) pq.push(v);
        }
        while (!pq.empty()) {
            long long tpq = pq.top();
            pq.pop();
            res+=tpq*tpq;
        }
        cout << res <<endl;
    }
}
