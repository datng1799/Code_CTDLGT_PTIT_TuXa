#include <bits/stdc++.h>

using namespace std;

int a[105];
int buoc = 0, N;
bool flag = false;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i<=N; i++) cin >> a[i];
    while (true) {
        flag = false;
        for (int j = 0; j<=N-1; j++)
        if (a[j]>a[j+1]) {
            flag = true;
            swap(a[j], a[j+1]);
        }
        if (flag) {
            buoc++;
            cout <<"Buoc "<<buoc<<":";
            for (int k = 1; k <= N; k++) cout << " "<<a[k];
            cout << endl;
        } else break;
    }
}
