#include <iostream>

using namespace std;

int n;
int demA = 0, demB = 0, demC = 0;
string Result = "";

void printResult() {
    if (demC!=0&&demB!=0&&demA!=0)
        if (demC>=demB&&demB>=demA)
            cout <<Result<<endl;
}

void backtrack(int y, int k) {
    if (y == k+1) {
        printResult();
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (i==1) {
            Result += 'A';
            demA++;
            backtrack(y+1, k);
            demA--;
            Result.pop_back();
        } else if (i==2) {
            Result += 'B';
            demB++;
            backtrack(y+1, k);
            demB--;
            Result.pop_back();
        } else {
            Result += 'C';
            demC++;
            backtrack(y+1, k);
            demC--;
            Result.pop_back();
        }

    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int k = 3; k <= n; k++) {
        backtrack(1, k);
    }
}
