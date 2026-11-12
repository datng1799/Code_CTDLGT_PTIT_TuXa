#include <iostream>

using namespace std;
long long L[55];

int T;
int N;
long long S;

void init() {
    L[0] = 0;
    L[1] = 1;
    for (int i = 2; i <= 51; i++) {
        L[i] = 2*L[i-1]+1;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    //for (int i =1; i<=5; i++) cout << L[i] <<" ";
    cin >> T;
    while (T--) {
        cin >> N >> S;

        //--------- solve ------//

        while ( L[N] )  {
            long long len = L[N];
            //cout <<len << endl;
            long long mid = (long long) len/2+1;
            //cout << mid << endl;
            if (S == mid) {
                cout << N << "\n";
                break;
            } else {
                if (S>mid) {
                    N--;
                    S -= mid;
                } else {
                    N--;
                }
            }
        }
        //--------- solve ------//
    }
}
