#include <bits/stdc++.h>
using namespace std;

int T, n;
stack <int> st;
int a[100005], val[100005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        while (!st.empty()) st.pop();
        cin >> n;
        for (int i = 0; i<n; i++) cin >> a[i];
        for (int i = 0; i<n; i++) val[i] = 1;
        for (int i = 0; i<n; i++)
            if (st.empty()) st.push(i);
            else {
                while (a[st.top()]<=a[i]) {
                   val[i] +=val[st.top()];
                   st.pop(); if (st.empty()) break;
                }
                st.push(i);
            }
       for (int i = 0; i<n; i++) cout << val[i] <<" ";
       cout << endl;
    }
}
