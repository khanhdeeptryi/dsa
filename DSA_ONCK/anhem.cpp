
#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isBrother(Tree, int, int);

void run(int q, Tree T){
    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        if (isBrother(T, x, y)) cout << x << " va " << y << " la anh em\n ";
        else cout << x << " va " << y << " khong phai la anh em\n ";
    }
}

void insertNode(TNode* &p, int x) {
    if (p == NULL) p = CreateTNode(x);
    else {
        if (x < p->key) insertNode(p->pLeft, x);
        else if (x > p->key) insertNode(p->pRight, x);
    }
}

void Insert(Tree &T, int x) {
    insertNode(T.root, x);
}

TNode* findParent(TNode* root, int x) {
    if (root == NULL || root->key == x) return nullptr;
    if ((root->pLeft != nullptr && root->pLeft->key == x) || (root->pRight != nullptr && root->pRight->key == x)) {
        return root;
    }
    if (x < root->key) {
        return findParent(root->pLeft, x);
    }
    else if (x > root->key) {
        return findParent(root->pRight, x);
    }
}

bool isBrother(Tree T, int x, int y) {
    if (x == y) return false;
    TNode* parentX = findParent(T.root, x);
    TNode* parentY = findParent(T.root, y);
    if (parentX != nullptr && parentX == parentY) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);

    return 0;
}
