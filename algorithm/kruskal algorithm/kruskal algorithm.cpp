struct edge { // lưu cạnh
    int u, v, w;
    bl operator < (const edge& others) const { // định nghĩa toán tử < đê so sánh mà ko cần viết bool ngoài
        return w < others.w;
    }
};
v(edge) a, MST; // lưa mảng gốc và cây minimum spanning tree (MST)
vit father(MAXn); // dùng để lưu root của DSU
int n, m; ll d_MST = 0; // n đỉnh, m cạnh ở đồ thị gốc, d_MST là tổng trọng số cách đường đi của cây MST
int find(int u) { // hàm tìm kiếm của DSU
    if (u == father[u]) return u;
    father[u] = find(father[u]);
    return father[u];
}
bl check_combine(int u, int v) {
    /*
     thay vì gộp đỉnh như bình thường, ta kết hợp với check xem 2 node có cùng tổ tiên không luôn
     nếu cùng ta loại và ko làm gì nữa
     nếu ko cùng ta cho gốc của 1 node là node còn lại sau đó chả về true
     */
    u = find(u); v = find(v);
    if (u == v) return false;
    father[v] = u; return true;
}
bl cmp(const edge& l, const edge& r) { return l.w < r.w; } // hàm bool ngoài để so sánh nếu không dùng operator
// thuật toán kruskal's
void kruskal() {
     for (int i = 0; i < m; ++i) { // duyệt qua tât các cách cạnh đã sắp xếp tăng dần ở đồ thị gốc
         if (check_combine(a[i].u, a[i].v)) { // nếu 2 node có khác gốc
             MST.pub({a[i].u, a[i].v, a[i].w}); d_MST += a[i].w;
             /*
             thêm node u, v và trọng số w vào trong cây MST và khoảng cách += trọng số giữa 2 đỉnh
            */
         }
         if (MST.size() == n - 1) break; // theo tính chất cây khung thì nếu tổng cạnh trong MST = số đỉnh - 1 thì là đủ
     }
}
void input() noexcept(true) {
    inall(n, m); // nhập bth
    for (int i = 1; i <= m; ++i) {
        int u, v, w; inall(u, v, w);
        a.pub({u, v, w});
    }
    TIME;
}
void output() noexcept(true) {
    sortt(a, cmp); // sort nếu ko dùng operator
    sort(a.begin(), a.end()); // sort nếu dùng operator
    for (int i = 1; i <= n; ++i) father[i] = i; // đầu tiên cha của mọi định là chính nó
    kruskal(); // gọi kruskal
    cout << d_MST << '\n'; // in trọng số MST
    for (auto& c : MST) { 
        outall(' ', c.u, c.v, c.w); cout << '\n'; // in cây MST;
    }
    TIME;
}
