#include <bits/stdc++.h>
using namespace std;
stack <char> st;

int T;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >>  T;
    while (T--){
        while (!st.empty()) st.pop();
        bool flag = true;
        string s;
        cin >> s;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '{'||s[i] == '['||s[i] == '(') st.push(s[i]);
            if (s[i] == '}') {
                if (st.empty()||st.top()!='{') {
                    flag = false;
                    break;
                }
                st.pop();
            }
            if (s[i] == ']') {
                if (st.empty()||st.top()!='[') {
                    flag = false;
                    break;
                }
                st.pop();
            }
            if (s[i] == ')') {
                if (st.empty()||st.top()!='(') {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        if (flag) cout << "YES" <<endl;
        else cout <<"NO"<<endl;
    }
}
