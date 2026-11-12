#include <bits/stdc++.h>

using namespace std;

int Test, N;
int a[1005];

void Postorder(int left, int right) {
    if (left>right) return;
    int root = a[left];
    int mid = left+1;
    while (mid<=right && a[mid]<root) mid++;
    Postorder(left+1, mid-1);
    Postorder(mid, right);
    cout << root << " ";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test --) {
        cin >> N;
        for (int i = 0; i<N; i++) cin >> a[i];
        Postorder(0, N-1);
        cout << endl;
    }
}
