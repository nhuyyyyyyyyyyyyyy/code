// Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. 
// Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited [1001];
int ID[1001];
int n,m,q;
int dem = 0;

void nhap() {
    cin >> n >> m;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for ( int i = 1; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void DFS(int u) {
    visited[u] = true;
    ID[u] = dem;
    for ( int x : ke[u]) {
        if ( !visited[x]) {
            DFS(x);
        }
    }
}

void DFS_path () {
    for (int i = 1; i < n + 1; i++) {
        if ( ! visited[i]) {
            dem++;
            DFS(i);
        }
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (ID[x] == ID[y]) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    DFS_path();
    return 0;
}