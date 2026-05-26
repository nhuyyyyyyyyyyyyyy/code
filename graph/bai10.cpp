//dfs tren do thi co huong
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
bool visited[1001];

void dfs(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int x : ke[u] ) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for (int i = 1; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
    dfs(s);
    return 0;
}