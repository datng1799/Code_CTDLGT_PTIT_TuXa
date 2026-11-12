#include <bits/stdc++.h>
using namespace std;

string s;
deque <char> dq1;
stack <char> st2;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;

    for (int i = 0; i<s.size(); i++) {
        //-----//
        if (s[i]== '<') {
            if (dq1.size() == 0) continue;
            else {
                char val1 = dq1.back();
                dq1.pop_back();
                st2.push(val1);
            }
        }
        else
        if (s[i] == '>') {
            if (st2.size() == 0) continue;
            else {
                char val2 = st2.top();
                dq1.push_back(val2);
                st2.pop();
            }
        }
        else
        if (s[i] == '-') {
            if (dq1.size() == 0) continue;
            else dq1.pop_back();
        }
        else dq1.push_back(s[i]);
    }
    string res = "";
    while (!dq1.empty()) {
        res += dq1.front();
        dq1.pop_front();
    }

    while (!st2.empty()) {
        res += st2.top();
        st2.pop();
    }
    cout << res << endl;
}
