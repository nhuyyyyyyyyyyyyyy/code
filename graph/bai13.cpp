// dem so thanh phan lien thong cua do thi
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[1001];
bool visited[1001];

void nhap() {
    cin >> n >> m;
    for (int i = 1; i < m + 1; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 1; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
    }
}

void DFS(int u) {
    visited[u] = true;
    for (int x : ke[u]) {
        if (! visited[x]) {
            DFS(x);
        }
    }
}

int countConnected() {
    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            sum++;
            DFS(i);
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    // int sum = 0;
    // for (int i = 1; i < n + 1; i++) {
    //     if (!visited[i]) {
    //         sum++;
    //         DFS(i);
    //     }
    // }
    cout << countConnected();
    return 0;
}