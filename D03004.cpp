#include <bits/stdc++.h>
using namespace std;

int T;
int scanString(const string &s) {
    int res = 0;
    int opening = 0;
    stack <char> st;

    for (int i = 0 ; i<s.size(); i++) {
        if (s[i] == ')')
            if (opening == 0) {
            res++;
            opening ++;
            st.push('(');
        } else {
            opening--;
            st.pop();
        }

        if (s[i] == '(') {
            opening++;
            st.push(s[i]);
        }
    }
    res += opening/2;
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << scanString(s) << endl;
    }
}
