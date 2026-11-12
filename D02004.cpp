#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

vector <ull> fibo;
int N, T;
ull I;

void init() {
    ull a1 = 0;
    ull a2 = 1;
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i<93; i++) {
        ull a3 = a1 + a2;
        fibo.push_back(a3);
        a1 = a2;
        a2 = a3;
    }
}
int findPos(int N,ull i) {
    while (N) {
      ull Left = fibo[N-2];
      ull Right = fibo[N-1];
      if (i<=Left) {
          N = N-2;
      } else  {
          N = N-1;
          i-=Left;
      }
      if (N==1||N==2) return(N);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    cin >> T;
    while (T--) {
        cin >> N >> I;
        int res = findPos(N, I);
        if (res == 1) cout <<"A" <<endl;
        else cout <<"B"<<endl;
    }
}
