#include <bits/stdc++.h>

using namespace std;

vector <int> P;
vector <int> N;
bool cnt(int &a, int &b) {
    return (a>b);
}
int NN;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> NN;
    int inp;
    for (int i = 0; i<NN; i++) {
        cin >> inp;
        if (inp<0) N.push_back(inp);
        else P.push_back(inp);
    }

    sort(P.begin(),P.end(), cnt);
    sort(N.begin(),N.end());
    //----------------------//
    if (P.size()==0) {
        cout << N[0]*N[1];
        return 0;
    }
    if (P.size()==1) {
        int res = max(N[0]*N[1]*P[0],N[0]*N[1]);
        cout << res;
        return 0;
    }
    if (N.size()==0) {
        int res = max(P[0]*P[1], P[0]*P[1]*P[2]);
        cout << res;
        return 0;
    }
    if (N.size()==1) {
        if (P.size()>=3) {
            int res = max(P[0]*P[1], P[0]*P[1]*P[2]);
            cout << res;
            return 0;
        }
        else {
            cout <<P[0]*P[1];
            return 0;
        }
    }

    if (P.size() == 2) {
        int res = max(N[0]*N[1]*P[0], P[0]*P[1]);
        return 0;
    }

    int res1 = max(N[0]*N[1]*P[0], N[0]*N[1]);
    int res2 = max(P[0]*P[1], P[0]*P[1]*P[2]);
    cout << max(res1, res2);
}
