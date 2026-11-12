#include <bits/stdc++.h>
using namespace std;
int b[17];
int N, T;
string inpStr;
vector <string> result;

void printResult() {
    string str ="";
    for (int i = 0; i < N; i++) {
       if (b[i] == 1) str += inpStr[i];
    }
    if (str != "") {
        result.push_back(str);
    }
}
void backtrack(int i) {
    if (i==N) {
        printResult();
        return;
    }
    for (int j = 0; j < 2; j++) {
        b[i] = j;
        backtrack(i+1);
    }
    b[i] = 0; // backtrack
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> inpStr;
        backtrack(0);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        result.clear(); // Clear the result vector for the next test case
    }
}
