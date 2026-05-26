//chuyen danh sach ke sang danh sach canh
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];

int main() {
    int n; cin >> n; cin.ignore();
    for ( int i = 1; i <= n; i++) {
        string s;
        getline(cin,s,'\n');
        stringstream ss(s);
        int x;
        while (ss >> x) {
            ke[i].push_back(x);
        }
    }
    for (int i = 1; i < n + 1; i++) {
        sort(ke[i].begin(), ke[i].end());
        for (int x : ke[i]) {
            if ( x > i) cout << i << " " << x << endl;;    
        }
    }
    return 0;
}