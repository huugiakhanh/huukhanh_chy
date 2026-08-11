#define biton(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | (1 << (i)))
#define MASK(i) (1ll << (i))

int n, cost[21][21]; ll dp[MASK(21)][21];
inline void input() noexcept(true) {
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> cost[i][j];
        }
    }
    TIME;
}
inline void output() noexcept(true) {
    int max_mask = MASK(n);
    FOR(mask, 0, max_mask) {
        FOR(i, 0, n) {
            dp[mask][i] = INF;
        }
    }
    dp[1][0] = 0;
    for (int mask = 1; mask < MASK(n); ++mask) {
        FOR(i, 0, n) {
            if (biton(mask, i) == 0) continue;
            if (dp[mask][i] == INF) continue;
            FOR(j, 0, n) {
                if (biton(mask, j) == 0) {
                    int next_mask = setbit(mask, j);
                    dp[next_mask][j] = min(dp[next_mask][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
    }
    ll ans = INF; ll last_mask = MASK(n) - 1;
    FOR(i, 1, n) {
        if (dp[last_mask][i] == INF) continue;
        ans = min(ans, dp[last_mask][i] + 1LL * cost[i][0]);
    }
    cout << ans;
    TIME;
}