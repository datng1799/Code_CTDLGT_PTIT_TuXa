#include <iostream>

using namespace std;

int N;
int dem0 = 0, dem1 = 0;
int a[16];
void backtrack(int i) {
    if (i == N) {
        if (dem1%2==1) return;
        for (int x = 0; x<N; x++ ) cout << a[x] << " ";
        cout << endl;
        return;
    }
    for (int j = 0; j<2; j++) {
        if (j == 0) {
                a[i] = j;
                dem0++;
        }
            else {
                a[i] = j;
                dem1++;
        }
        backtrack(i+1);
        if (j == 0) dem0--; else dem1--;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    backtrack(0);

}
