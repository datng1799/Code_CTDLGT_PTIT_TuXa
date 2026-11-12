#include <iostream>

using namespace std;

int N;
int dem1 = 0, dem2 = 0;
char a[16];
void backtrack(int i) {
    if (i == N) {
        for (int x = 0; x<N; x++ ) cout << a[x];
        cout << endl;
        return;
    }
    for (int j = 0; j<2; j++) {
        if (j == 0) {
                if (i==N-1 && dem2 == 0) continue;
                a[i] = 'A';
                dem1++;
        }
            else {
                if (i==N-1 && dem1 == 0) continue;
                a[i] = 'B';
                dem2++;
        }
        backtrack(i+1);
        if (j == 0) dem1--; else dem2--;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    backtrack(0);

}
