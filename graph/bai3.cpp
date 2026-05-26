// chuyen danh sach canh sang danh sach ke co huong
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; 
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";
        for (int x : ke[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}