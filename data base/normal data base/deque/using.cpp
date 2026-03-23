signed main() {
    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    deque<ll> qe; // khai báo
    qe.push_back(value); // thêm giá trị vào cuối deque
    qe.push_front(value); // thêm giá trị vào đầu hàng đợi
    qe.pop_front(); // xóa giá trị ở đầu phần tử
    qe.pop_back(); // xóa giá trị ở cuối hàng đợi
    qe.front(); // lấy giá trị đầu hàng đợi
    qe.back(); // lấy giá trị cuối hàng đợi
    qe.empty(); // kiểm tra có rỗ hay không
    qe.size(); // lấy độ dài của deque
    /// thao tác duyệt gần giống vector có thể thay thành iterator  
    // xuôi
    for (int i = 0; i < qe.size(); i++) {
        cout << qe[i] << " ";
    }
    // ngược
    for (int i = qe.size() - 1; i >= 0; i--) {
        cout << qe[i] << " ";
    }
    return 0;
}