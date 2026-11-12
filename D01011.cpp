#include <bits/stdc++.h>

using namespace std;

int  T, N, K;
int a[21];
void printResult() {
    for (int i = 1; i <= K; i++) cout <<a[i] <<" ";
    cout << endl;
}
void backtrack(int y, int pre) {
    if (y == K+1) {
        printResult();
        return;
    }

    for (int i = N - K + y; i>pre; i--) {
        a[y] = i;
        backtrack(y+1, i);
        a[y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        backtrack(1, 0);
    }
}
