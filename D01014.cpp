#include <bits/stdc++.h>

using namespace std;

int a[13];
int N, K;

void printResult() {
    for (int i=1; i<=K; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void backtrack(int y, int pre) {
    if (y == K+1) {
        printResult();
        return;
    }

    for (int i = pre; i <= N; i++) {
        a[y] = i;
        backtrack(y+1, i);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> K;
    backtrack(1,1);
}
