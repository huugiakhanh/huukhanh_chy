int a[MAXn]; // mảng a
ll BIT[MAXn]; // mảng lưu tổng a theo bit
int n, m; // mảng dài n, m truy vấn
void update(int idx, int val) { // cập nhật từ vị trí từ idx đến n theo kiểu bit với 1 lượng val
    for (; idx <= n; idx += (idx & -idx)) { // cộng toe LSB của i
        BIT[idx] += val; // cộng thêm 1 lượng val
    }
}
ll query(int idx) { // tổng từ 1 đến idx
    ll tatal = 0; // lưu ans
    for (; idx >= 1; idx -= (idx & -idx)) { // tính ngược từ index về 1 để tính tổng
        tatal += BIT[idx]; // cộng
    }
    return tatal;
}


// ứng dụng trong mảng 2 chiều
ll bit2d[505][505];
void update(int& x, int& y, int& delta) {
    for (int i = x; i <= n; i += (i & -i)) {
        for (int j = y; j <= m; j += (j & -j)) {
            bit2d[i][j] += delta;
        }
    }
}
ll query(int x, int y) {
    ll ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            ans += bit2d[i][j];
        }
    }
    return ans;
}

// VD chạy
void input() noexcept(true) {
    inall(n, m);
    forr(i, 1, n, 1) {
        cin >> a[i];
        update(i, a[i]); // nếu coi mảng BIT ban đầu bằng 0 thì t có thể + a[i] thẳng vào các bit tương ứng
    }
    TIME;
}
void output() noexcept(true) {
    while (m--) {
        short type; cin >> type;
        if (type == 1) {
            int idx, val; inall(idx, val);
            update(idx, val); // cập nhật từ vị trí từ idx đến n theo kiểu bit với 1 lượng val
        } else {
            int idx; cin >> idx;
            cout << query(idx) << '\n'; // tổng tư 1 đến i;
            // nếu muôn tính từ l đến r
            // ans = query(r) - query(l - 1);
        }
    }
    TIME;
}