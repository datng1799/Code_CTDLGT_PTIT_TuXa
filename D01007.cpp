#include <bits/stdc++.h>

using namespace std;
int T, N, K;
string strResult = "";
vector <int> Result;
int a[21];

void printResult() {
    for (int e: Result) cout <<e <<" ";
    cout <<endl;
}
void backtrack (int y, int pre) {
    if (y == K+1) {
        printResult();
        return;
    }
    for (int i = pre+1; i <= N - K + y; i++){
        Result.push_back(a[i]);
        backtrack(y+1, i);
        Result.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> a[i];
        sort(a+1, a+N+1);
        backtrack(1,0);
        //cout << endl;
    }
}
