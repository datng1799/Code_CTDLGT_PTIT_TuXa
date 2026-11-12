#include <bits/stdc++.h>
using namespace std;

int N;
int a[105];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector <int> vt;
    vt.push_back(0);
    int buoc = 0;
    scanf("%d", &N);
    for (int i = 1; i<=N; i++) scanf("%d", &a[i]);
    for (int i = 1; i<=N; i++) {
        int j = 0;
        while (a[i]>=vt[j]) {
                j++;
                if (j==vt.size()) break;
        }
        vt.insert(vt.begin()+j, a[i]);
        printf("Buoc %d:",buoc);
        for (int k = 1; k<vt.size();k++) printf(" %d", vt[k]);
        printf("\n");
        buoc++;
    }
}
