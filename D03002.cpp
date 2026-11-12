#include <bits/stdc++.h>
using namespace std;

int T;
string s;
stack <int> st;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        int res = 0;
        int opening = 0;
        while (!st.empty()) st.pop();
        cin >> s;
        for (int i = 0; i<s.size(); i++) {
             if (s[i] == '(') {
                st.push(i);
                opening++;
             }
             if (s[i] == ')') {
                if (opening == 0) st.push(i);
                else {
                    st.pop();
                    opening--;
                }
             }
        }
        int ii = s.size()-1;
        while (ii>=0) {
            if (!st.empty()) {
                res = max(res, ii - st.top());
                ii = st.top()-1;
                st.pop();
            }
            else {
                res = max(res, ii+1);
                ii = -1;
            }
        }
        cout << res << endl;
    }
}
