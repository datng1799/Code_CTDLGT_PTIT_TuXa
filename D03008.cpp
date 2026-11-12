#include <bits/stdc++.h>

using namespace std;


stack <int> st;
string s;
int T;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while  (T--) {
        while (!st.empty()) st.pop();
        cin >> s;
        for (int i = s.size()-1; i>=0; i--) {
            if (s[i]!='*'&&s[i]!='/'&&s[i]!='+'&&s[i]!='-') {
                int val1 = int (s[i] - '0');
                st.push(val1);
            } else {
                int val1, val2;
                if (s[i] == '*') {
                    val1 = st.top();
                    st.pop();
                    val2 = st.top();
                    st.pop();
                    st.push(val1*val2);
                }
                //---------------//
                if (s[i] == '/') {
                    val1 = st.top();
                    st.pop();
                    val2 = st.top();
                    st.pop();
                    st.push(val1/val2);
                }
                //----------------//
                if (s[i] == '+') {
                    val1 = st.top();
                    st.pop();
                    val2 = st.top();
                    st.pop();
                    st.push(val1+val2);
                }
                //------------------//
                if (s[i] == '-') {
                    val1 = st.top();
                    st.pop();
                    val2 = st.top();
                    st.pop();
                    st.push(val1-val2);
                }
            }
        }
        cout << st.top() <<endl;
    }
}
