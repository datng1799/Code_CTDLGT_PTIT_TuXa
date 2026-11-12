#include <bits/stdc++.h>
using namespace std;


struct Time{
    int Tbegin;
    int Tend;
};

Time w[100005];
int T, N;

int d[100005];
bool cnt(Time &a, Time &b) {
    if (a.Tend==b.Tend) return(a.Tbegin<b.Tbegin);
    return (a.Tend<b.Tend);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i<=N; i++) {
            cin >> w[i].Tbegin >> w[i].Tend;
        }
        sort(w+1, w+N+1, cnt);
        int lastEnd = 0;
        int res = 0;
        for (int i=1; i<=N; i++) {
            if (w[i].Tbegin>=lastEnd) {
                res++;
                lastEnd = w[i].Tend;
            }
        }
        cout << res <<endl;
    }
}
