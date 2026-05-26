// duyet inorder( l n r)
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

// sau khi tim duoc cha
void makeRoot(Node* root,int u, int v, char c) {
    if ( c == 'L') root->left = new Node(v);
    else root -> right = new Node(v);
}
// cho v la node con cua u
void insertNode(Node* root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->val == u ) {
        makeRoot(root,u,v,c);
    }
    else {
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}

void preorder(Node* root) {
    if ( root == NULL) return;
    cout << root ->val << ' ';
    preorder(root -> left);
    preorder(root ->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = NULL;
    int n; cin >> n;
    for ( int i = 0; i < n; i++) {
        int u; int v; char c;
        cin >> u >> v >> c;
        if ( root == NULL) {
            root = new Node(u);
            makeRoot(root, u, v, c);
        } 
        else {
            insertNode(root,u,v,c);
        }
    }
    preorder(root);
    return 0;
}