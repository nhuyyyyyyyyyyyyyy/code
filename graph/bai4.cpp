//chuyen tu danh sach ke sang danh canh co huong
#include<bits/stdc++.h>

using namespace std;

vector<int> ke[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; cin.ignore();
    for (int i = 1; i < n + 1; i++) {
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
            cout << i << " " << x << '\n';
        }
    }
    return 0;
}