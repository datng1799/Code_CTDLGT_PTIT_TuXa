#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector <string> names(n);
    for (int i = 0; i<n; i++) cin >> names[i];

    string last;
    cin >> last;

    vector <string> rest;
    for (int i = 0; i<n; i++) {
        if (names[i]!=last) rest.push_back(names[i]);
    }

    sort(rest.begin(), rest.end());
    do {
        for (int i = 0; i<(int) rest.size(); i++) {
            cout << rest[i] << " ";
        }
        cout << last <<"\n";
    } while (next_permutation(rest.begin(), rest.end()));
}
