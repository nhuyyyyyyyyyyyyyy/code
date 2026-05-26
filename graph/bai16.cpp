// duong di tren do thi co huong bang bfs
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited[1001];
int parent[1001];
int n,m,s,t;

void nhap() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for (int i = 1 ; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void DFS (int u) {
    visited[u] = true;
    for (int x : ke[u]) {
        if (!visited[x]) {
        parent[x] = u;
        DFS(x);
        }
    }
}

void DFS_Path() {
    DFS(s);
    if (!visited[t]) cout << -1 << '\n';
    else {
        vector<int> res;
        while ( s != t) {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (int x : res) {
            cout << x << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    DFS_Path();
    return 0;
}