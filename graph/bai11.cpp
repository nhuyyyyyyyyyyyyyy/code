// bfs tren do thi vo huong
#include<bits/stdc++.h>

using namespace std;

int n, m,s;
vector<int> ke[1001];
bool visited[1001];

void nhap() {
    cin >> n >> m >> s;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 0; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int y : ke[x]) {
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    BFS(s);
    return 0;
}