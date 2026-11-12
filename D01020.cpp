#include <bits/stdc++.h>
using namespace std;

int N, K;
int ord = -1;
int a[16];
void printResult() {
    ord++;
    if (ord%K!=0) return;
    for (int i = 1; i <=K; i++) cout <<a[i]<<" ";
    cout << endl;

}

void backtrack(int y, int pre) {
    if (y == K+1) {
        printResult();
        return;
    }

    for (int i = pre+1; i <= N-K+y; i++) {
        a[y] = i;
        backtrack(y+1, i);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    backtrack(1, 0);
}
