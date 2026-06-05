// chu trinh do thi

#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited[1001];
int parent[1001];
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

int DFS(int u) {
    int ok = 0;
    visited[u] = true;
    for ( int x : ke[u]) {
        if ( !visited[x]) {
            parent[x] = u;
            DFS(x);
        }
        else if ( x != parent[u] ) {
            ok = 1;
            return ok;
        }
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    int curr = 0;
    for (int i = 1; i < n + 1; i++) {
        if (! visited[i]) {
            if (DFS(i) == 1) {
                curr = 1;
                cout << 1;
                break;
            }
        }
    }
    if (curr != 1) cout << 0;
    return 0;
}