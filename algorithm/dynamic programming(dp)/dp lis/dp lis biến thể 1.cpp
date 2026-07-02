int l1, l2, l3, c1, c2, c3, n, s, t; vit a(MAXn); vll dp(MAXn);
int get_cost(int distant) {
    if (distant >= 0 && distant <= l1) return c1;
    if (distant > l1 && distant <= l2) return c2;
    if (distant > l2 && distant <= l3) return c3;
}
void input() noexcept(true) {
    inall(l1, l2, l3, c1, c2, c3, n, s, t);
    forr(i, 2, n) cin >> a[i];
    TIME;
}
void output() noexcept(true) {
    if (s > t) swap(s, t); // trường hợp từ điểm đi lơn hơn điểm đến t swap lại cho thuận
    forr(i, 0, n) dp[i] = LLONG_MAX; // b3: trường hợp cơ sở
    dp[s] = 0; // chi phí từ s là bắt đầu nên bằng 0
    //b1: dp[i] là chi phí nhỏ nhất từ s đến i
    forr(i, s + 1, t) { // bắt đầu từ ga s + 1 đến t
        rfor(j, i - 1, s) { // b2: tính dp[i] = dp[j] từ s đến i - 1, có thể forr(j, s, i - 1) nhưng trường hợp len > l3 thì continue chứ không break
            int len = a[i] - a[j]; // tính khoảng cách
            if (len > l3) continue;
            dp[i] = min(dp[i], dp[j] + get_cost(len)); // b2: tính dp[i] = dp[i] = min(dp[i], dp[j] + get_cost(len)) // j từ s đến i - 1
        }
    }
    cout << dp[t]; // chi phí min từ s đến t
    TIME;
}