int n, k, a[MAXn], b[MAXn], sz;
ll dp[MAXn][15], ans = 0;
ll fen[MAXn];
void update(int idx, int val) {
    for (; idx <= sz; idx += (idx & -idx)) fen[idx] += val;
}
ll query(int idx) {
    ll ans = 0;
    for (; idx > 0; idx -= (idx & -idx)) ans += fen[idx];
    return ans;
}
ll query(int l, int r) {
    return query(r) - query(l);
}
ll bif(int val) {
    return lower_bound(b + 1, b + sz + 1, val) - b;
}
void input() noexcept(true) {
    inall(n, k); forr(i, 1, n) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1); sz = unique(b + 1, b + n + 1) - (b + 1);
    TIME;
}
void output() noexcept(true) {
    mset(dp, 0);
    forr(i, 1, n) dp[i][1] = 1;
    forr(len, 1, k) {
        mset(fen, 0);
        forr(i, 1, n) {
            int ci = bif(a[i]);
            dp[i][len] = (dp[i][len] + query(ci, sz) + MOD1) % MOD1;
            update(ci, dp[i][len - 1]);
        }
    }
    forr(i, 1, n) ans += dp[i][k];
    cout << ans % MOD1;
    TIME;
}