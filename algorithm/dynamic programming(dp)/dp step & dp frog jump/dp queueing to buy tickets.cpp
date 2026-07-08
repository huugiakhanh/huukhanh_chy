int n; vit t(MAXn), r(MAXn), dp(MAXn, INT_MAX);
// t là thời gian nếu i tự mua vé cho i
// r là thời gian nếu i mua vé và mua vé cho i + 1
// b1: gọi dp[i] là thời gian tối thiểu để xử lý xong cho i người đầu tiên trong hàng.
void input() noexcept(true) {
    cin >> n;
    forr(i, 1, n) cin >> t[i];
    forr(i, 1, n - 1) cin >> r[i];
    TIME;
}
void output() noexcept(true) {
    dp[0] = 0; dp[1] = t[1]; //b3: trường hợp cơ sở
    // người 1 chỉ mua vé cho chính nó <=> dp[1] = t[1]
    // người 0 ko thể mua bế nên dp[0] = 0;
    forr(i, 2, n) {
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]); // b2: dp[i] được tính
        // là min của dp[i - 1] + t[i] và dp[i - 2] + r[i - 1]
        // trong đó dp[i - 1] + t[i] là người i tự mua vé cho chính nó, dp[i - 1] là tối ưu trc của người i;
        // và dp[i - 2] + r[i - 1] là người i - 1 mua vé cho người i, dp[i - 2] là tối ưu trc của người i - 1
    }
    cout << dp[n];
    TIME;
}