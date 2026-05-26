#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
int a[1001][1001];

int main() {
    int n; cin >> n;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                ke[i].push_back(j);
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
        for ( int x : ke[i]) {
            cout << i << " " << x << '\n';
        }
    }
    cout << endl;
    for (int i = 1; i < n + 1; i++) {
        cout << i << " : ";
        for (int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}