int a[MAXn]; // mảng a
ll segment_tree[4 * MAXn + 1]; // cây phân đoạn của a,
// do t chia đôi và lưu giá trị mảng a nhiều lần
// nên ta cần kích thứóc của của cây là 4 * n;

void build_tree(int idx, int l, int r) noexcept(true) { // xây cây dùng đệ quy
    if (l == r) { // nếu l == r thì cập nhẩt i
        segment_tree[idx] = a[l]; // pử dây ta có thể thay đổi thành tất nhiều kiểu
        // vd :
        /*
            kiểm tra bằng k
            tree[idx] = (a[l] == k);

            đêm chẵn lẻ
            if ((a[l] & 1) == 0) tree[idx] = a[l];
            else tree[idx] = INT_MAX;

            đêm nếu a[l] thảo mãi điều kiện
            if (check(a[l])) tree[idx] = a[l];
            else tree[idx] = 0;

            tổng chẵn lẻ riêng với 2 tree
            if ((a[l] & 1) == 0) {
                treechan[idx] = a[l];
                treele[idx] = 0;
            }
            else {
                treechan[idx] = 0;
                treele[idx] = a[l];
            }

            và còn rất nhiều ứng dụng khác
         */
        return;
    }
    int mid = (l + r) >> 1;
    // ta có nếu đếm từ trái sang phải thì tại node index 2 node kề với nó tiếp theo là 2 * idx và 2 * idx + 1
    build_tree(2 * idx, l, mid);
    build_tree(2 * idx + 1, mid + 1, r);
    // với các cách build khác nhau ta có những cách xử lí khác nhau
    // vd đơn giản nhẩt là tổng
    segment_tree[idx] = segment_tree[2 * idx] + segment_tree[2 * idx + 1];
}
void update(int idx, int l, int r, int pos, int val) noexcept(true) {
    /*
     với l r là giới hạn cập nhật, ql qr là giới giạn của mảng hoặc giới hạn cập nhât,
     val là thường là lượng tăng hoặc giảm hoắc các thao tác khác của cây trên đoạn l r
     */
    if (l == r) {
        // cập nhật vị trí idx thành value mới
        segment_tree[idx] = val;
        return;
        // ở đâu cần đồng bộ với void build ở trên
    }
    int mid = (l + r) >> 1;
    // nếu vị trí ta càn cập nhât <= vị trí giữa thì ta tính vào tường hợp 2 * idx từ l đến mid
    // nếu ko ta tính trường hợp còn lại là 2 * idx + 1 từ mid + 1 đến r
    if (pos <= mid) update(2 * idx, l, mid, pos, val);
    else update(2 * idx + 1, mid + 1, r, pos, val);
    // với vd nì ta tính tổng
    segment_tree[idx] = segment_tree[2 * idx] + segment_tree[2 * idx + 1];
}
ll query(int idx, int l, int r, int& ql, int& qr) {
    if (l > qr || r < ql) return 0; // nếu l hoặc r năm ngoài giới han ta trả nề 0, hoặc tùy theo ý tưởng đề bài
    if (ql <= l && r <= qr) return segment_tree[idx]; // nếu l và r trong giới hạn, trà về giá trị index
    int mid = (l + r) >> 1;
    // nếu muốn tính tổng của index t cần bt giá trị của 2 node kề nó là 2 * idx, và 2 * idx + 1
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}
int n, m; // kích thước mảng và m query
void input() noexcept(true) {
    inall(n);
    forr(i, 1, n, 1) cin >> a[i];
    build_tree(1, 1, n);
    cin >> m;
    TIME;
}
void output() noexcept(true) {
    while (m--) {
        sh type; cin >> type;
        if (type == 1) {
            int pos, val; inall(pos, val);
            update(1, 1, n, pos, val);
        } else {
            int l, r; inall(l, r);
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    TIME;
}
