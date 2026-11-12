#include <bits/stdc++.h>

using namespace std;

int T;
long long a[100005];
long long L[100005], R[100005];
stack <long long> st1, st2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        long long res = 0;
        while (!st1.empty()) st1.pop();
        while (!st2.empty()) st2.pop();
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        int n;
        cin >> n;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        //---------------------//
        for (int i = 0; i<n; i++) {
            if (st1.empty()) {
                st1.push(i); L[i] = 0;
            } else {
                while (a[st1.top()]>=a[i]) {
                    L[i] += L[st1.top()] + 1;
                    st1.pop(); if (st1.empty()) break;
                }
                st1.push(i);
            }
        }
        //for (int i = 0; i<n; i++) cout << L[i] <<" ";
        //cout << endl;
        //---------------------------//
         for (int i = n-1; i>=0; i--) {
            if (st2.empty()) {
                st2.push(i); R[i] = 0;
            } else {
                while (a[st2.top()]>=a[i]) {
                    R[i] += R[st2.top()] + 1;
                    st2.pop(); if (st2.empty()) break;
                }
                st2.push(i);
            }
        }
        //for (int i = 0; i<n; i++) cout << R[i] <<" ";
        //cout << endl;
        //---------------------------//

        for (int i = 0; i<n; i++) {
            res = max (res, (L[i]+R[i]+1)*a[i]);
        }
        cout << res << endl;
    }
}
