// ma tran ke sang danh sach ke, danh sach canh vo huong

#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];
int a[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                ke[i].push_back(j);
            }
        }
    }

    for (int i = 2; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
        for (int x : ke[i]) {
            if ( x < i ) cout << i << " " << x << '\n';
        }
    }
    cout << '\n';
    for (int i = 1; i < n + 1; i++ ) {
        cout << i << " : ";
        for (int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}