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


void duyetXoanOc(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    // Biến cờ: true là đi từ Trái sang Phải, false là Phải sang Trái
    bool leftToRight = true; 
    
    while (!q.empty()) {
        int size = q.size(); // Chốt số lượng node của mức hiện tại
        vector<int> levelNodes; // Mảng trống để chứa giá trị
        
        for (int i = 0; i < size; i++) {
            Node* crr = q.front();
            q.pop();
            
            // 1. CỨ ĐẨY VÀO MẢNG BÌNH THƯỜNG
            levelNodes.push_back(crr->val);
            
            // 2. CỨ ĐẨY CON TRÁI, CON PHẢI VÀO QUEUE BÌNH THƯỜNG
            if (crr->left != NULL) q.push(crr->left);
            if (crr->right != NULL) q.push(crr->right);
        }
        
        // 3. XỬ LÝ LẬT NGƯỢC (Đoạn dễ hiểu nhất)
        // Nếu cờ đang là false (yêu cầu in từ Phải sang Trái), ta lật ngược mảng lại
        if (leftToRight == false) {
            reverse(levelNodes.begin(), levelNodes.end());
        }
        
        // In mảng ra màn hình
        for (int val : levelNodes) {
            cout << val << " ";
        }
        
        // Đổi trạng thái cờ cho mức tiếp theo (Từ true thành false, false thành true)
        leftToRight = !leftToRight; 
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
    duyetXoanOc(root);
    return 0;
}

