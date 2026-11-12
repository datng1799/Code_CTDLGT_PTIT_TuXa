#include <bits/stdc++.h>

using namespace std;
int order = 0;
int n;
vector <int> Result;

void printResult() {
    order++;
    if (order%2 ==0 ) {
        cout <<order<<": ";
        for (int e:Result) cout << e;
        cout << endl;
    }
}

void backtrack(int x) {
    if (x == n+1) {
        printResult();
        return;
    }
    for (int i = 0; i<3; i++) {
        Result.push_back(i);
        backtrack(x+1);
        Result.pop_back();
    }
}
int main()
{
    cin >> n;
    backtrack(1);
}
