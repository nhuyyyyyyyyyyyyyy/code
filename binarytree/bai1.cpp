// duyet inorder( l n r)
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    Node* l;
    Node* r;
    Node(int x) {
        key = x;
        l = r = NULL;
    }
};

// sau khi tim duoc cha
void makeRoot(Node* root,int u, int v, char c) {
    if ( c == 'L') root->l = new Node(v);
    else root -> r = new Node(v);
}
// cho v la node con cua u
void insertNode(Node* root, int u, int v, char c) {
    if (root == NULL) return;
    if (root->key == u ) {
        makeRoot(root,u,v,c);
    }
    else {
        insertNode(root->l,u,v,c);
        insertNode(root->r,u,v,c);
    }
}

void inorder(Node* root) {
    if ( root == NULL) return;
    inorder(root -> l);
    cout << root ->key << ' ';
    inorder(root ->r);
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
    inorder(root);
    return 0;
}