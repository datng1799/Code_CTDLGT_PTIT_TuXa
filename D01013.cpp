#include <bits/stdc++.h>
using namespace std;

int N ,M;
bool used[11];
int a[11];

void printResult() {
    for (int i = 1; i<=N; i++) cout << a[i] <<" ";
    cout <<endl;
}
void backtrack(int y) {
    if (y == N+1) {
        printResult();
        return;
    }

    for (int i = 1; i<=N; i++) {
        if (i == M && y<N) continue;
        if (used[i]) continue;
        used[i] = true;
        a[y] = i;
        backtrack(y+1);
        used[i] = false;
        a[y] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;
    backtrack(1);
}
