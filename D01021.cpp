#include <bits/stdc++.h>
using namespace std;

vector <string> names;
vector <string> result;
set <string> result_base;

int status[17];
int N;

void printResult(){
    string s = "";
    for (int i = 0; i<N; i++) {
        if (status[i]) s+=names[i];
    }
    if (s!="") result_base.insert(s);
}
void backtrack(int y) {
    if (y == N) {
        printResult();
        return;
    }

    for (int i = 0; i<2; i++) {
        status[y] = i;
        backtrack(y+1);
        status[y] = 0;
    }
}

bool cnt(string &a, string &b) {
    int minLength = min(a.size(), b.size());
    for (int i = 0; i<minLength; i++) {
        if (a[i]<b[i]) return(a<b);
    }
    if (a.size()<=b.size()) return (a<b);
    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    names.resize(N);

    for (int i = 0; i<names.size(); i++)
        cin >> names[i];

    backtrack(0);

    for (string str:result_base) {
        result.push_back(str);
    }

    sort(result.begin(), result.end(), cnt);
    for (int i = 0; i<result.size(); i++) {
        cout <<  result[i] <<endl;
    }
}
