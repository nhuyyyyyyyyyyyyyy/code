// cay nhi phan hoan hao
// tat ca cac node khong phair node la deu co 2 con & node la cung muc
// viet ham kiem tra nhung dieu do: full + cung muc

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

bool isCungMuc (Node* root, int level, int& currLevel) {
    if ( root == NULL) return false;
    if (isLeaf(root)) {
        if (currLevel == 0) currLevel = level;
        if (currLevel != level ) return false;
    }
    return isCungMuc(root->left, level + 1, currLevel) && isCungMuc(root->right, level + 1, currLevel);
}

bool isFull(Node* root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left != NULL && root->right != NULL) {
        return isFull(root->left) && isFull(root->right);
    }
    return false;
}

bool isPerfectBinary(Node* root) {
    int currLevel = 0;
    return isFull(root) && isCungMuc(root,1,currLevel);
}

// Hàm kiểm tra 1-pass: kết hợp cả isFull và isCungMuc
// Trả về chiều sâu của cây con nếu nó là cây nhị phân hoàn hảo, ngược lại trả về -1
int checkPerfect(Node* root) {
    // Trường hợp gốc rỗng
    if (root == NULL) return 0; 

    // Nếu là node lá (không có con trái và con phải)
    if (root->left == NULL && root->right == NULL) {
        return 1; // Độ sâu tương đối của node lá hiện tại là 1
    }

    // Nếu thiếu 1 trong 2 con -> Vi phạm điều kiện Full Binary Tree
    if (root->left == NULL || root->right == NULL) {
        return -1;
    }

    // Gọi đệ quy kiểm tra độ sâu của 2 nhánh con
    int leftDepth = checkPerfect(root->left);
    int rightDepth = checkPerfect(root->right);

    // Nếu cả 2 nhánh con đều là cây hoàn hảo (khác -1) và có độ sâu bằng nhau
    if (leftDepth != -1 && leftDepth == rightDepth) {
        return leftDepth + 1; // Chiều sâu cây hiện tại = chiều sâu cây con + 1
    }

    // Trả về -1 nếu vi phạm bất kỳ điều kiện nào
    return -1;
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
    if (isPerfectBinary(root)) cout << "YES";
    else cout << "NO";
    return 0;
}

