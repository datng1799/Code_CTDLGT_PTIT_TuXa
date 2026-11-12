#include <bits/stdc++.h>

using namespace std;

int Test, N;
int a[1005];

int Postorder(int left, int right, int _rank) {
    if (left>right) return (_rank-1);
    int root = a[left];
    int mid = left+1;
    while (mid<=right && a[mid]<root) mid++;
    int P_left = Postorder(left+1, mid-1, _rank+1);
    int P_right = Postorder(mid, right,_rank+1);
    return max(P_left, P_right);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test --) {
        cin >> N;
        for (int i = 0; i<N; i++) cin >> a[i];
        cout << Postorder(0, N-1, 0) << endl;
    }
}
