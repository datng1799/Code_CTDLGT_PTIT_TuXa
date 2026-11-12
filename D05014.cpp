#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string val;                 // giữ nguyên dạng chuỗi, in ra luôn
    Node *l = nullptr, *r = nullptr;
};

void NRL(Node* p)
{
    if (!p) return;
    cout << p->val << ' ';
    NRL(p->r);
    NRL(p->l);
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string line;
        do getline(cin, line);
        while (line.empty());

        stringstream ss(line);
        vector<string> a;
        string s;
        while (ss >> s) a.push_back(s);

        Node* root = new Node{a[0]};
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (i < a.size())
        {
            Node* cur = q.front();
            q.pop();
            if (a[i] != "N")
            {
                cur->l = new Node{a[i]};
                q.push(cur->l);
            }
            i++;
            if (i < a.size() && a[i] != "N")
            {
                cur->r = new Node{a[i]};
                q.push(cur->r);
            }
            i++;
        }

        NRL(root);
        cout << '\n';
    }
    return 0;
}
