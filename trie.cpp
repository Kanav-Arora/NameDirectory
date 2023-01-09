#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *child[62]; // 0-9, a-z and A-Z
    bool terminal;

    Node(int val)
    {
        terminal = false;
        data = val;

        for (int i = 0; i < 63; i++)
            child[i] = NULL;
    }
};

void insert(Node *root, string s, int i)
{
    if (i < 0)
    {
        root->terminal = true;
        return;
    }

    int val = 0;

    if (s[i] >= '0' && s[i] <= '9')
        val = (s[i] - '0');

    else if (s[i] >= 'a' && s[i] <= 'z')
        val = (s[i] - 'a') + 10;

    else if (s[i] >= 'A' && s[i] <= 'Z')
        val = (s[i] - 'A') + 36;

    Node *n = new Node(val);
    root->child[val] = n;

    insert(root->child[val], s, i + 1);
}

int main()
{
    cout << ('A' - 'A') + 36;
    return 0;
}