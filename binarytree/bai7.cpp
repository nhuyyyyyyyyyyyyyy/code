// kiem tra cac node la cung muc

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

void makeRoot(Node* root, int u, int v, char c) {
    if ( c == 'L') root->left = new Node(v);
    else {
        root->right = new Node(v);
    }
}

void insertNode(Node* root, int u, int v, char c) {
    if ( root == NULL) return;
    if (root->val == u) {
        makeRoot(root,u,v,c);
    }
    else {
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}

bool isLeaf(Node* node) {
    if (node == NULL) return false;
    return (node->left == NULL && node->right == NULL);
}

// currlevel luu muc cua node la dau tien
// khi duyet root -> level = 1
// de quy trai phai lam level tang len

bool cungMuc(Node* root, int level, int &currlevel) {
    if( root == NULL) return true;
    if (isLeaf(root)) {
        if ( currlevel == 0) currlevel = level;
        if (currlevel != level) return false;
    }
    return cungMuc(root->left, level + 1, currlevel) && cungMuc(root->right, level + 1, currlevel);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    Node* root = NULL;
    for ( int i = 0; i < n; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if ( root == NULL) {
            root = new Node(u);
            makeRoot(root,u,v,c);
        }
        else {
            insertNode(root,u,v,c);
        }
    }
    int currlevel = 0;
    if (cungMuc(root,1,currlevel)) cout << "YES";
    else cout << "NO";
    return 0;
}