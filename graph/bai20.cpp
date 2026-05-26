// canh cau
#include <bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited[1001];
vector<pair<int,int>> edge;
int n,m;

void nhap() {
    cin >> n >> m;
    for ( int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        edge.push_back({x,y});
    }
}

void DFS(int u, int s, int t) {
    visited[u] = true;
    for ( int x : ke[u]) {
        if (s == u && t == x || s == x && u == t) continue;
        if (!visited[x]) {
            DFS(x,s,t);
        }
    }
}

int tplt(int s, int t) {
    int dem = 0;
    for ( int i = 1; i < n + 1; i++){
        if (!visited[i]) {
            dem++;
            DFS(i,s,t);
        }
    }
    return dem;
}

int demCanhCau() {
    int dem = 0;
    int cc = tplt(0,0);
    for (auto e : edge) {
        memset(visited, false, sizeof(visited));
        int s = e.first; int t = e.second;
        if ( cc < tplt(s,t)) dem++;
    }
    return dem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    cout << demCanhCau();
    return 0;
}