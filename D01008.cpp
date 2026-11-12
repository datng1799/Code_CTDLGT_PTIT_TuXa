#include <bits/stdc++.h>

using namespace std;

int n, k;
int checkOdd = 0;
vector <int> Result;

void printResult() {
    if (checkOdd%2 == 0) {
        for (int e:Result) cout << e <<" ";
        cout <<endl;
    }
}
void backtrack(int x, int pre) {
    if (x == k+1) {
        printResult();
        return;
    }
    for (int i = pre+1; i<=n-k+x; i++) {
        checkOdd += i;
        Result.push_back(i);
        backtrack(x+1, i);
        Result.pop_back();
        checkOdd -=i;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    backtrack(1,0);
}
