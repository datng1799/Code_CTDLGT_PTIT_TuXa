#include <bits/stdc++.h>

using namespace std;

int N;
bool fibo[5000005];
int ord = 0;
int a[16];
void init() {
    fibo[1] = true;
    fibo[2] = true;
    int a1 = 1, a2 = 2;
    for (int i = 1; i < 31; i++) {
        int a3 = a1 + a2;
        a1 = a2;
        a2 = a3;
        //cout << a3 <<endl;
        fibo[a3] = true;
    }
}
void printResult() {
    ord++;
    if (!fibo[ord]) return;
    printf("%d: ",ord);
    for (int i = 1; i<=N; i++) printf("%d ", a[i]);
    printf("\n");
}
void backtrack(int y) {
    if (y == N+1) {
        printResult();
        return;
    }

    for (int i = 0; i<2; i++) {
        a[y] = i;
        backtrack(y+1);
    }
}
int main()
{
   ios::sync_with_stdio(false); cin.tie(nullptr);
   init();
   cin >> N;
   backtrack(1);
}
