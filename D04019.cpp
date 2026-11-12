#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

vector <Edge> edges;
int parent[1005];
int sz[1005];
int N, M, Test;

int find_p(int x) {
    return x==parent[x]? x:parent[x] = find_p(parent[x]);
}

bool Union(int a, int b) {
    a = find_p(a);
    b = find_p(b);
    if (a == b) return false;
    if (sz[a] <sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(const Edge &a, const Edge &b) {
    return a.w<b.w;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> Test;
    while (Test -- ) {
        cin >> N >> M;
        // ---- khoi tao cha cac dinh la chinh no
        // ----- kich thuoc cay chua dinh la 1
        for (int i = 1; i<=N; i++) {
            parent[i]  = i;
            sz[i] = 1;
        }
        // --- nhap du lieu canh
        for (int i = 0; i<M; i++) {
            Edge e;
            cin >> e.u >> e.v >> e.w;
            edges.push_back(e);
        }
        // --- sort lai danh sach canh giam dan theo do dai
        sort(edges.begin(), edges.end(),cmp);

        long long res = 0;
        int count_edge = 0;
        for (auto e:edges) {
            if (Union(e.u, e.v)) {
                res += e.w;
                count_edge ++;
                if (count_edge == N-1) break;
            }
        }
        edges.clear();
        cout << res <<endl;
    }
}
