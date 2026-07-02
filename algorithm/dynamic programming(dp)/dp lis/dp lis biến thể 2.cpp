int n, p; vit a(MAXn); vll dp(MAXn);
ll get_punish(ll dis) {
    ll cur = dis - p;
    return cur * cur;
}
void input() noexcept(true) {
    inall(n, p);
    forr(i, 1, n) cin >> a[i];
    TIME;
}
void output() noexcept(true) {
    //b1: dp[i] = là tiền phạt nhỏ nhất đến i
    forr(i, 1, n) {
        dp[i] = get_punish(a[i]); //b3: trường hợp cơ sở
        forr(j, 1, i - 1) { // b2: dp[i] đc tính là dp[j] j từ 1 đến i - 1
            ll punish = get_punish(a[i] - a[j]); // theo đề thình tính cost là bình phương khoảng cách đi được - đi trọng số cho trước
            dp[i] = min(dp[i], dp[j] + punish); // dp[i] = min(dp[i], dp[j] + cost);
        }
    }
    cout << dp[n] << '\n'; // tiền phạt nhỏ nhất đến n
    TIME;
}