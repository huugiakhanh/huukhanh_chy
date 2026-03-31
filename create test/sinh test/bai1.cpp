#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);
    int n; cin >> n;
    long long tong = 0;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num; tong += num;
    }
    cout << tong << '\n';
    return 0;
}
