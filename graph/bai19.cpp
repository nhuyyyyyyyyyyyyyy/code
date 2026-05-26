// dinh tru
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited[1001];
int n,m;

void nhap() {
    cin >> n >> m;
    for ( int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u) {
    visited[u] = true;
    for ( int x : ke[u]) {
        if ( !visited[x]) {
            visited[x] = true;
            DFS(x);
        }
    }
}

int tplt() {
    int dem = 0;
    for (int i = 1; i < n + 1; i++) {
        if ( !visited[i]) {
            dem++;
            DFS(i);
        }
    }
    return dem;
}

int demDinhTru() {
    int dem = 0;
    int cc = tplt();
    for (int i = 1; i < n + 1; i++) {
        memset(visited,false,sizeof(visited));
        visited[i] = true;
        int res = tplt();
        if ( cc < res) {
            dem++;
        }
    }
    return dem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    demDinhTru();
    return 0;
}