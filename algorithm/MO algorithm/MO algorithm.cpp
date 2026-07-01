struct node {
    int l, r, idx;
} queries[MAXn]; // lưu để sort lại truy vấn
int n, q; // q truy vấn
ll block; // về lí thuyệt, ta có thể trọn giá trị bất kì cho block để làm giá trị chia
// nhưng thé tính toán block = sqrt(n) là có độ phức tạp tốt nhất
int a[MAXn];
ll res[MAXn]; // lưu lại các query đê in ra
vit cnt(MAXn); // cnt để đếm số lương phần từ a[i] trpng đoạn l, r giúp tăng tốc độ tính toán
int cur_l = 1, cur_r = 0; // nếu a đánh từ 1 đến n
// int cur_l = 0, cur_r = -1; // nếu a đánh từ 0 đến n - 1
ll cur_ans = 0; // lưu kết quả sau mỗi lần add và remove
bool cmp(const node& L, const node& R) {
    int g_l = L.l / block, g_r = R.l / block; // tính xem 2 truy vấn này có cùng 1 khối i đến i + block - 1 không
    if (g_l != g_r) return g_l < g_r; // nếu không cho thằng có g_ bé hơn lên trước;
    return L.r < R.r; // nếu cùng một block thì ưu tiên r từ bé đến lớn
}
void add(int idx) {
    cnt[a[idx]]++; // thêm giá trị a[idx] vào ta tăng lên
    if (cnt[a[idx]] == 1) cur_ans++; // ví dụ bài đếm số phần từ khác nhau trên đoạn
}
void remove_(int idx) {
    if (cnt[a[idx]] == 0) return; // nếu a[idx] không có trong đoạn thì không xử lí
    cnt[a[idx]]--; // xóa đi một gía trị của a[idx] trong đoạn l r mới
    if (cnt[a[idx]] == 0) cur_ans--; // nêu trong đoạn l r mới mà cnt[a[idx]] == 0 tức không có, ta xóa luôn
}
/*
NÂNG CAO HƠN:
ll f_x(int val) { return cnt[val] * cnt[val] * val; }
void add(int idx) {
    cur_ans -= f_x(a[idx]);
    cnt[a[idx]]++;
    cur_ans += f_x(a[idx]);
}
void remove_(int idx) {
    cur_ans -= f_x(a[idx]);
    cnt[a[idx]]--;
    cur_ans += f_x(a[idx]);
}
void add(int x) noexcept(false) {
    res += (2 * cnt[x] + 1);
    cnt[x]++;
}

void remove(int x) noexcept(false) {
    res += (-2 * cnt[x] + 1);
    cnt[x]--;
}
V.V....
 */
void input() noexcept(true) {
    cin >> n;
    forr(i, 1, n) cin >> a[i];
    block = max(1, (int)sqrt(n)); // lấy căn n;
    cin >> q;
    forr(i, 0, q - 1) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r, (int)i}; // i để sau khi chạy xong in ra thứ tự gốc các truy vấn
    }
    sort(queries, queries + q, cmp);
    TIME;
}
void output() noexcept(true) {
    forr(i, 0, q - 1) {
        int L_ = queries[i].l, R_ = queries[i].r;
        // cout << L_ << " " << R_ << '\n';
        while (R_ > cur_r) {
            cur_r++; add(cur_r); // nếu r trước nhỏ hơn r hiện tại, ta tăng r và thêm giá trị
        } while (R_ < cur_r) {
            remove_(cur_r); cur_r--; // nếu r trước nhỏ hơn r hiện tại thì ta xóa a[r] và giảm r đi
        } while (L_ > cur_l) {
            remove_(cur_l); cur_l++; // nếu l trước nhỏ hơn l hiện tại tức ta cần tăng l trước lên và xóa đi các giá trị l trước dó, hay l -> l + 1 thì xóa giá trị a[l]
        } while (L_ < cur_l) {
            cur_l--; add(cur_l); // nếu l trước lớn hơn giá trị l hiện tại tức ta cần giảm l trước và thêm các giá trị l sau vào, hay l -> l - 1 thì thêm giá trị a[l]
        }
        cur_r = R_, cur_l = L_; // để cho truy vấn sau
        res[queries[i].idx] = cur_ans; // lưu giá trị
    }
    forr(i, 0, q - 1) cout << res[i] << '\n';
    TIME;
}
