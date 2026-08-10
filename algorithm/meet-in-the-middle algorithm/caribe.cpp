int n; ll k; vit a(MAXn), b(MAXn);
v(pll) L_val, R_val, max_val_in_R; ll ans = 0;
inline v(pll) get_subtract(int l, int r) {
    v(pll) cur_ans; int len = r - l + 1;
    for (int mask = 0; mask < MASK(len); ++mask) {
        ll sum_weight = 0, sum_cost = 0;
        forr(i, 0, len - 1) {
            if (biton(mask, i)) {
                sum_weight += a[l + i];
                sum_cost += b[l + i];
            }
        }
        cur_ans.pub({sum_weight, sum_cost});
    }
    return cur_ans;
} inline ll bif(ll limit_) {
    int l = 0, r = (int)max_val_in_R.size() - 1; ll cur_ans = 0;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (max_val_in_R[mid].F <= limit_) {
            cur_ans = max_val_in_R[mid].S;
            l = mid + 1;
        } else r = mid - 1;
    }
    return cur_ans;
}

inline void input() noexcept(true) {
    inall(n, k);
    forr(i, 1, n) inall(a[i], b[i]);
    int mid = n >> 1;
    L_val = get_subtract(1, mid);
    R_val = get_subtract(mid + 1, n);
    TIME;
}
inline void output() noexcept(true) {
    sort(All(R_val)); ll cur_max_cost = -1;
    for (auto p : R_val) {
        if (p.S > cur_max_cost) {
            cur_max_cost = p.S;
            max_val_in_R.pub(p);
        }
    }
    for (auto p : L_val) {
        ll w1 = p.F, v1 = p.S;
        if (w1 > k) continue;
        ll limit_w = k - w1;
        ll best_val = bif(limit_w);
        ans = max(ans, v1 + best_val);
    }
    cout << ans;
    TIME;
}