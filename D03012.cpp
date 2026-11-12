#include <bits/stdc++.h>

using namespace std;

queue <string> q1;
queue <int> q2;
int T, n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        while (!q1.empty()) {
            q1.pop();
            q2.pop();
        }
        q1.push("9"); q2.push(9%n);

        while (true) {
            string s = q1.front();
            int val = q2.front();
            q1.pop(); q2.pop();

            if (val == 0) {
                cout << s <<endl;
                break;
            }

            q1.push(s+"0"); q2.push((val*10)%n);
            q1.push(s+"9"); q2.push((val*10+9)%n);
        }
    }
}
