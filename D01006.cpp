#include <bits/stdc++.h>

using namespace std;

string strInp, strResult = "";
vector <string> Result;
bool used[21][10];
int a[21];
int  T,N,K;

void printResult(){
    Result.push_back(strResult);
}

void backtrack(int y, int pre) {
    if (y == K+1) {
            printResult();
            return;
    }
    for (int i = pre+1; i<=N-K+y; i++) {
        if (used[y][a[i]]) continue;
        strResult = strResult + strInp[i-1];
        used[y][a[i]] = true;
        backtrack(y+1, i);
        //-------//
        used[y+1][0] = false;
        used[y+1][1] = false;
        used[y+1][2] = false;
        used[y+1][3] = false;
        used[y+1][4] = false;
        used[y+1][5] = false;
        used[y+1][6] = false;
        used[y+1][7] = false;
        used[y+1][8] = false;
        used[y+1][9] = false;
        strResult.pop_back();
        //---------//
    }
}

bool cmp (string &a, string &b) {
    if (a.size()!=b.size()) return(a.size()<b.size());
    return (a<b);
}
int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> strInp;
        N = strInp.size();
        for (int i=0; i<N; i++)
            a[i+1] = (int) strInp[i] - '0';
        //for (int i = 1; i<=N; i++)
         //   cout << a[i]<<" ";
        cin >> K;
        //cout << K;
        memset(used, false, sizeof(used));
        if (K == 1)
            used[1][0] = true;
        backtrack(1,0);
        sort(Result.begin(), Result.end(), cmp);
        for (string str: Result) cout << str <<endl;
        Result.clear();
    }
}
