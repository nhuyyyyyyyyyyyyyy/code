//ma tran trong so trong danh sach canh
#include<bits/stdc++.h>

using namespace std;

struct edge {
    int dau, cuoi, w;
};

vector<edge> ke[1001];
int a[1001][1001];

int main() {
    int n ; cin >> n;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            cin >> a[i][j];
            if ( a[i][j] != 0) {
                edge crr;
                crr.dau = i;
                crr.cuoi = j;
                crr.w = a[i][j];
                ke[i].push_back(crr);
            }
        }
    }
    for ( int i = 1; i < n + 1; i++) {
        for (edge x : ke[i]) {
            if ( i < x.cuoi) cout << x.dau << " " << x.cuoi << " " << x.w << '\n';
        }
    }
    return 0;
}