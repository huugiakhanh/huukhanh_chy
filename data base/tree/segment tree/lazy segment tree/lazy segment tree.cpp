int a[MAXn];
ll tree[4 * MAXn], lazy[4 * MAXn];
void build (int idx, int l, int r) noexcept(true) {
    if (l == r) {
        // đây là thông tin loại 1
        tree[idx] = a[l]; // ở đây cần xác định thông tin loại 1 tức thông tin để tra lới query
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    // đây là thông tin 1
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1]; // vd thao tac luu tong
}
void push_down (int idx, int l, int r) noexcept(true) {
    /*
    đây là thao tác từ node cha t tinh cho 2 node con 2 * idx và 2 * idx + 1
    Thao tác push-down: Sử dụng thông tin loại 2 của nút cha (nút i) cập nhật
    cho thông tin loại 1 và thông tin loại 2 ở hai nút con (2 * i và 2 * i + 1).
    Khi kết thúc hàm push-down, ta xóa thông tin loại 2 ở nút cha.
    */
    if (lazy[idx] == 0) return; // nếu nó không mang thông tin gì ta bỏ qua
    int mid = (l + r) >> 1;
    tree[2 * idx] += lazy[idx] * (mid - l + 1); // đây là thông tin loại 2 nhưng t cần xác định từ đề bài
    tree[2 * idx + 1] += lazy[idx] * (r - mid);
    lazy[2 * idx] += lazy[idx];
    lazy[2 * idx + 1] += lazy[idx];
    lazy[idx] = 0; // xóa lazy[idx] có thể đặt là giá trị khác
}
void update(int idx, int l, int r, int ql, int  qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        tree[idx] += 1LL * val * (r - l + 1);
        lazy[idx] += val; return;
    }
    push_down(idx, l, r);
    int mid = (l + r) >> 1;
    update(2 * idx, l, mid, ql, qr, val);
    update(2 * idx + 1, mid + 1, r, ql, qr, val);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1]; // đay còn là thao tác push_up
}
ll query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    push_down(idx, l, r); // push thêm trong mỗi query trong trường hợp nó chx đc tính
    int mid = (l + r) >> 1;
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}
int n, m;
void input() noexcept(true) {
    inall(n);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    TIME;
}
void output() noexcept(true) {
    while (m--) {
        sh type; cin >> type;
        if (type == 1) {
            int l, r, val; inall(l, r, val);
            update(1, 1, n, l, r, val);
        } else {
            int l, r; inall(l, r);
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    TIME;
}
/*
    cở bản khi xác định có dùng lazy ko t chỉ cần biểu diễn 2 day khi cập nhật
    nếu có thể tính nhanh hoặc có thể tìm ra được điểm chung gần nhất thì t có thể dung lazy;
 */