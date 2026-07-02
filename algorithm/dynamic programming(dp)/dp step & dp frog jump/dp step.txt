int n; vit a(MAXn);
vit dp(MAXn, 0);
void input() noexcept(true) {
    cin >> n; forr(i, 1, n) cin >> a[i];
    TIME;
}
void output() noexcept(true) {
    //b1: dp[i] là điểm lớn nhất có thể chọn mà không có quá 2 phần từ liên tiếp
    dp[0] = 0, dp[1] = a[1]; //b3: trường hợp cơ sở
    if (n >= 2) {
        dp[2] = max({a[1] + a[2], dp[0] + a[2], dp[1]}); // nới ở dưới
    }
    forr(i, 3, n) {
        int cost_1 = dp[i - 1];
        int cost_2 = dp[i - 2] + a[i];
        int cost_3 = dp[i - 3] + a[i] + a[i - 1];
        // vì ko quá 2 phần từ liên tiếp nên
        //b2:
        // dp[i] có 3 trường hợp: 
        // 1 là không chọn i tức dp[i] = max(dp[i], dp[i - 1]);
        // 2 là chọn i không chọn i - 1 ta đươc, dp[i] = max(dp[i], dp[i - 2] + a[i]);
        // 3 là chọn cả i và i - 1 ta được, dp[i] = max(dp[i], a[i - 1] + a[i] + dp[i - 3]); // không chọn đc dp[i - 2] vì nêu chọn là 3 phần từ liên tiếp sai đề
        int cost = max({cost_1, cost_2, cost_3});
        dp[i] = cost;
    }
    cout << dp[n] << '\n';
    TIME;
}