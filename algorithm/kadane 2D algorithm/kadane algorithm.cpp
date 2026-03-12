ll tong1D(vector<ll> a, ll n) {
    ll tong = a[0];
    ll tongmax = a[0];
    for (ll i = 1; i < n; i++) {
        tong = max(a[i], tong + a[i]);
        tongmax = max(tong, tongmax);
    }
    return tongmax;
}

ll tong2D(vector<vector<ll>>& a, ll& m, ll& n) {
    ll RES = INT_MIN;
    for (ll i = 0; i < m; i++) {
        vll res(n);
        for (ll idx = i; idx < m; idx++) {
            for (ll j = 0; j < n; j++) {
                res[j] += a[idx][j];
            }
            ll tongmax1 = tong1D(res, n);
            RES = max(RES, tongmax1);
        }
    }
    return RES;
}
int main() {
    ll m, n; cin >> m >> n;
    vvll(a, m, n);
    FOR(i, m) {
        FOR(j, n) {
            cin >> a[i][j];
        }
    }
    cout << tong2D(a, m, n);
}
