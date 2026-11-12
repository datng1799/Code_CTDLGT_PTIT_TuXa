#include <bits/stdc++.h>
using namespace std;

int T, N, K;
vector <int> a;

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin >>  T;
    while (T--) {
        cin >> N >> K;
        a.resize(N);
        for (int i = 0; i<N; i++) cin >> a[i];
        vector <int>::iterator it;
        it = find(a.begin(), a.end(), K);
        if (it!=a.end())  {
                int index = distance(a.begin(), it);
                cout <<index+1 <<endl;
        }
        else cout << "NO" << endl;
    }
}
