#include <bits/stdc++.h>
using namespace std;

int N, K;

bool prime[1000005];
int a[21];
int ord = 0;

void sangnt() {
    prime[1] = true;
    for (int i = 2; i<=1000; i++) {
        if (prime[i] == 0)
        for (int j = i*i; j<=1000000; j+=i) {
            prime[j] = true;
        }
    }
}
void printResult() {
    ord++;
    if (prime[ord]) return;
    printf("%d: ", ord);
    for (int i = 1; i<=K; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void backtrack(int y, int pre) {
    if (y == K+1) {
        printResult();
        return;
    }

    for (int i = pre+1; i<=N; i++) {
        a[y] = i;
        backtrack(y+1, i);
        a[y] = 0;
    }
}
int main()
{
   ios::sync_with_stdio(false); cin.tie(nullptr);
   sangnt();

   cin >> N >> K;
   backtrack(1, 0);
}
