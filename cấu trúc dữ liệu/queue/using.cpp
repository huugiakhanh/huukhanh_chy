signed main() {
    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    queue<ll> qe; // khai báo
    qe.push(value); // thêm giá trị vào cuối hàng đợi
    qe.front(); // lấy giá trị đầu hàng đợi
    qe.pop(); // xóa giá trị ở đầu hàng đợi
    qe.empty(); // kiểm tra rỗ hay ko
    qe.size(); // lấy kích thước hàng đợi
    /// thao tác duyệt
    while (!qe.empty()) {
        cout << qe.front() << " ";
        qe.pop();
    }
    return 0;
}