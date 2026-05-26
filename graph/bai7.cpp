#include<bits/stdc++.h>

using namespace std;

int main () {
    int n; int m;
    cin >> n >> m;
    int a[1001][1001];
    for (int i = 1; i < n+1; i++) {
        for ( int j = 1; j < n+1; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u; int v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (int i = 1; i < n+1; i++) {
        for ( int j = 1; j < n+1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}