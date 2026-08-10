// Hàm inline sinh tất cả các tổng của một tập con trong khoảng [l, r]
inline void get_half(int l, int r, vector<ll>& res) {
    int len = r - l + 1;
    // Dùng bitmask để sinh tập con O(2^(N/2))
    for (int mask = 0; mask < (1LL << len); ++mask) {
        ll sum = 0;
        for (int i = 0; i < len; ++i) {
            if (mask & (1LL << i)) {
                sum += a[l + i]; // đoạn này khi lấy giá trị là name_arr[l + i]
            }
        }
        res.pub(sum);
    }
}


// VD hàm khác
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
}

// xử lí trong main
int mid = n >> 1;
get_half(1, mid, L_val);
get_half(mid + 1, n, R_val);
sort(all(R_val));
// 3. Meet in the middle: Ghép kết quả
ll ans = 0;
for (ll x : left_sums) {
   // Tìm giá trị thảo mãi trong R_val
    
}


