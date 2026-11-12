#include <bits/stdc++.h>

using namespace std;

int Test;
int N;
int a[1000005];
int main()
{
    cin >> Test;
    while (Test --) {
        cin >> N;
        for (int i = 0; i<N; i++)
            cin >> a[i];
        sort(a, a+N);
        cout << a[(N-1)/2] <<endl;
    }
}
