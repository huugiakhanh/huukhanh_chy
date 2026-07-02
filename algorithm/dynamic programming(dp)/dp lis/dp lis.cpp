int n; vit a(MAXn), dp(MAXn);
void input() noexcept(true) {
    cin >> n; forr(i, 1, n) cin >> a[i];
    TIME;
}
void output() noexcept(true) {
    forr(i, 1, n) {
        dp[i] = 1; // b3: trường hợp cơ sở là mỗi vị trí i thì trường hợp tệ nhất ta lấy chính nó lên dp[i] = 1
        forr(j, 1, i - 1) { // b2: để tính dp[i] ta cần xem, từ 1 đến i - 1 ta có bao nhiêu số < a[i], để chọn 
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1); 
            // khi đó dp[i] = max(dp[i], dp[j] + 1); dp[j] + 1 thức, lấy dp[j] và cộng thêm 1 chính là a[i]
        }
    }
    cout << *max_element(dp.begin(), dp.begin() + n + 1) << "\n";
    // lấy giá trị max trong đoạn từ 1 đến n vì dp[n] là dãy con tốt nhất kết thúc tại n chứ chưa chắc là dãy con tốt nhẩt từ 1 đến n
    TIME;
}