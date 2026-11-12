#include <iostream>

using namespace std;

int N;
int a[10005];
int f[10005];
int last[10005];
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i<=N; i++) {
            cin >> a[i];
            last[i] = 1000000007;
    }
    last[0] = 0;
    for (int i = 1; i<=N; i++) {
        int l = 0;
        int r = i-1;
        while (l<=r) {
            int mid = (l+r)/2;
            if (last[mid]<a[i]) {
                last[mid+1] = min(last[mid+1],a[i]);
                f[i] = mid+1;
                l = mid+1;
            } else {
                r= mid-1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i<=N;i++)
        res = max(res, f[i]);
    cout << res;
}
