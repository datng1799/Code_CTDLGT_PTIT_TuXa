#include <bits/stdc++.h>
using namespace std;

stack <char> st;
int T;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    cin.ignore();
    while (T--)
    {
        string s;
        getline(cin, s);
        bool flag = true;
        bool ngoac = false;
        while (!st.empty()) st.pop();
        //-----------------//
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] != ')') {
                st.push(s[i]);
            }
            else {
                flag = false;
                while (st.top()!='(') {

                    if (st.top()=='+'||st.top()=='-'
                        ||st.top()=='*'||st.top()=='/') flag = true;
                    st.pop();
                }
                st.pop();
                if (flag == false) {
                    cout << "Yes" <<endl;
                    break;
                }
            }
        }
        if (flag) cout << "No" <<endl;
    }
}
