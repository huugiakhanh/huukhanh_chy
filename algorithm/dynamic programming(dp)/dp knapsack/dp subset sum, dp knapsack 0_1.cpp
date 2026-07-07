int n; vit a(MAXn); bl dp[MAXn];
void input() noexcept(true) {
    mset(dp, false); cin >> n;
    forr(i, 1, n) cin >> a[i];
    TIME;
}
void output() noexcept(true) {
    //b1: dp[i] = true\false dãy a có thể tạo đc tổng i
    dp[0] = true; // b3: cách tạo tổng 0 là không chọn số vào nên luôn đúng
    forr(i, 1, n) {
        rfor(s, 20000, a[i]) { //b2: duyệt tổng mảng a (ơ đây để 1 giá trị cố định vì test bé)
            if (dp[s - a[i]]) dp[s] = true; // nếu tổng s nào đó - a[i] tồn tại tức tồn tại tổng mà + a[i] = s <=> s tồn tại
            /* vd: a = 1 2 3 5
             *  dp[7 - 2] = dp[5] = true <=> dp[7] = true
             */
        }
    }
    forr(i, 1, 20000) {
        if (dp[i]) cout << i << ' ';
    }
    /* tối ưu bitset vì chỉ cần true / false;
     * bitset<tổng mảng a> dp
     * duyệt hết mảng a dp |= dp << a[i]
     * tức ta or của mảng dp với a[i] tức Tập_tổng_mới = Tập_tổng_cũ HỢP VỚI (Tập_tổng_cũ cộng thêm a[i])
     * vd: 1 3 4
     * bitset<8> dp = {1 | 0 0 0 0 0 0 0 0} toán tử << trong bitset giống xử lí bit thưởng
     * xét a[1] = 1; dp |= dp << 1 <=> dp = 1 1 | 0 0 0 0 0 0 0 (có thể tạo tổng 1 và 0)
     * xét a[2] = 3; dp |= dp << 3 <=> dp = 1 1 0 1 1 0 0 0 0 (có thể tạo tổng 0, 1, 3, 4)
     * xét a[3] = 4; dp |= dp << 4 <=> dp = 1 1 0 1 1 1 0 1 1 (có thể tạo tổng 0, 1, 3, 4, 5, 7, 8)
     */
}