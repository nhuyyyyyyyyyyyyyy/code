// duyet theo muc

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


// vector<int> ke[1001];
// int visited[1001];

// void bfs(int u) {
//     queue<int> q;
//     q.push(u);
//     visited[u] = true;
//     while (!q.empty()) {
//         int curr = q.front();
//         q.pop();
//         for (int x : ke[u]) {
//             if (!visited[x]) {
//                 q.push(x);
//                 visited[x] = true;
//             }
//         }
//     }
// }

void duyetTheoMuc(Node* root) {
    if ( root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* crr = q.front();
        q.pop();
        cout << crr->val << " ";
        if (crr->left != NULL) q.push(crr->left);
        if (crr->right != NULL) q.push(crr->right);  
    }
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
    duyetTheoMuc(root);
    return 0;
}

