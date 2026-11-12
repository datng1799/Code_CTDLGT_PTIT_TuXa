#include <bits/stdc++.h>
using namespace std;

int biggerNum[105];
int smallerNum[105];
int N, S;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    scanf("%d%d", &N, &S);

    if (N==1) {
        if (S>9) printf("-1 -1");
        else printf("%d %d", S, S);
        return 0;
    }
    if (N>=2) {
        if (S<2||S>N*9) {
            printf("-1 -1");
            return 0;
        }
    }
    // dung so lon nhat
    int S2 = S;
    int i = 0;
    while (S2) {
        int deg = min(9, S2);
        biggerNum[i] = deg;
        S2 -= deg;
        i++;
    }
    //dung so lon nhat

    // dung so nho nhat
    int S3 = S;
    i = 0;
    while (S3>9) {
        smallerNum[i] = 9;
        S3 -= 9;
        i++;
    }
    if (i==N-1) {
        smallerNum[i] = S3;
    }
    if (i<N-1) {
        smallerNum[i] = S3-1;
    }
    for (int j = i+1; j<N-1; j++) {
        smallerNum[j] = 0;
    }
    if (i<N-1) smallerNum[N-1] = 1;
    //dung so nho nhat

    for (int i = N-1; i>=0; i--) printf("%d", smallerNum[i]);
    printf(" ");
    for (int i = 0; i<N; i++) printf("%d", biggerNum[i]);
}
