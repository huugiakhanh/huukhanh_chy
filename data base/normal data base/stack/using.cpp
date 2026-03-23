signed main() {
    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    stack<ll> st; // khai bao
    st.push(value); // thêm giá trị vào đỉnh
    st.pop(); // xóa phần tử ở đỉnh
    st.top(); // lấy giá trị trên đỉnh stack
    st.size(); // lấy kích thước stack
    st.empty(); // kiêm tra rỗ
    /// thao tác duyệt
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}