#include <bits/stdc++.h>
using namespace std;

int T, N;
vector <int> a;
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        a.resize(N);
        for (int i = 0; i<N; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i<N; i++) cout << a[i] <<" ";
        cout << endl;
    }
}
