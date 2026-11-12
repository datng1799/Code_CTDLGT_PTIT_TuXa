#include <bits/stdc++.h>
using namespace std;


int T;

int scanString(const string &s) {
    int res = 0;
    stack <char> st;
    for (int i = 0; i<s.size(); i++) {
        if (s[i] == '(') st.push(s[i]);
        if (s[i] == ')') {
            if (st.empty()) st.push(s[i]);
            else if (st.top() == ')') st.push(s[i]);
            else {
                st.pop(); res +=2;
            }
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << scanString(s) <<endl;
    }
}
