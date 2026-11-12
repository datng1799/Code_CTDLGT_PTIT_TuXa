#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;


    long long total = 1;
    for (int i = 0; i < n; i++) total *= 3;


    const char digit[3] = {'A', 'B', 'C'};


    for (long long i = 0; i < total; i++) {
        long long order = i + 1;


        if (order % 2 == 1) {
            long long value = i;
            string s(n, ' ');

            for (int pos = n - 1; pos >= 0; pos--) {
                s[pos] = digit[value % 3];
                value /= 3;
            }

            cout << order << ": " << s << "\n";
        }
    }

    return 0;
}
