#include <bits/stdc++.h>

using namespace std;

int Test, N;
int a[1000005];

void find_root(int left, int right) {
    if (left > right) return;
    int mid = (left+right)/2;
    find_root(left, mid-1);
    find_root(mid+1, right);
    cout << a[mid] <<" ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> Test;
    while (Test -- ) {
        cin >> N;
        for (int i = 0; i<N ;i++)
            cin >> a[i];
        sort(a, a+N);
        find_root(0, N-1);
        cout << endl;
    }
}
