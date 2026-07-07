int n, m; int root[MAXn];
// DSU hay Disjoint Set Union là cấu trúc là một cấu trúc dữ liệu có thể quản lí một cách hiệu quả một tập hợp của các tập hợp.
// bài toán tính điển :
//Cho một đồ thị có n đỉnh, ban đầu không có cạnh nào. Chúng ta phải xử lí các truy vấn như sau:
// Thêm một cạnh giữa đỉnh x và đỉnh y trong đồ thị.
// In ra YES nếu như đỉnh x và đỉnh y nằm trong cùng một thành phần liên thông. In ra NO nếu ngược lại.
void input() noexcept(true) {
    inall(n, m);
    TIME;
}
// DSU có 3 thao tác đơn giản là:
// make_set(v) - tạo ra một tập hợp mới chỉ chứa phần tử v;
// union_sets(a, b) - gộp tập hợp chứa phần tử a và tập hợp chứa phần tử b thành một.
// ind_set(v) - cho biết đại diện của tập hợp có chứa phần tử v. Đại diện này sẽ là một phần tử của tập hợp đó và có thể thay đổi
// sau mỗi lần gọi thao tác union_sets. Ta có thể sử dụng đại diện đó để kiểm tra hai phần tử có nằm trong cùng một tập hợp hay không
// a và b nằm trong cùng một tập hợp nếu như đại diện của hai tập chứa chúng là giống nhau và không nằm trong cùng một tập hợp nếu ngược lại.
void make_setv1(int u) noexcept(true) {
    root[u] = u; // Tạo ra cây mới có gốc là đỉnh u
}
int find_setv1(int v) noexcept(true) {
    if (v == root[v]) return v; // Trả về đỉnh v nếu như đỉnh v là gốc của cây
    return find_setv1(root[v]);  // Đệ quy lên cha của đỉnh v
    // find_set đệ quy chư tối ưu độ phức tạp là O(n)
}
void union_setsv1(int u, int v) noexcept(false) {
    u = find_setv1(u); // Tìm gốc của cây có chứa đỉnh a
    v = find_setv1(v); // Tìm gốc của cây có chứa đỉnh b
    if (u != v) root[v] = u; // Gộp hai cây nếu như hai phần tử ở hai cây khác nhau
}
void outputv1() noexcept(true) {
    forr(i, 1, n, 1) make_setv1(i); // ban đầu tất cả các đỉnh đều là đỉnh cha của nó
    forr(i, 1, m, 1) {
        int type, u, v; inall(type, u, v);
        if (type == 1) {
            union_setsv1(u, v); // gộp 2 note vào 1 cha
        } else {
            // kiểm tra xem 2 note có cùng cha (có liên thông nhau hay không)
            if (find_setv1(u) == find_setv1(v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    TIME;
}
// Tối ưu 1 - Gộp theo kích cỡ / độ cao
// Chính xác hơn, ta sẽ thay đổi cách xét trong hai cây đang gộp, gốc của cây nào sẽ là cha của gốc của cây còn lại.
int sz[MAXn]; // lưu kích thước node cha
int h[MAXn]; // tối ưu theo chiều cao
void make_setv2(int v) {
    root[v] = v;
    sz[v] = 1; // Ban đầu tập hợp chứa v có kích cỡ là 1
    h[v] = 0; // Gốc của cây có độ cao là 0
}
int find_setv2(int v) noexcept(true) {
    if (v == root[v]) return v; // Trả về đỉnh v nếu như đỉnh v là gốc của cây
    return find_setv2(root[v]);  // Đệ quy lên cha của đỉnh v
    // find_set đệ quy tối ưu 1 độ phức tạp là O(logn)
}
void union_setsv2(int a, int b) {
    a = find_setv2(a);
    b = find_setv2(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
        root[b] = a;
        sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
        // if (h[a] == h[b]) h[a]++; // Nếu như hai cây có cùng một độ cao, độ cao của cây mới sau khi gộp sẽ tăng 1
    }
}
void outputv2() noexcept(true) {
    forr(i, 1, n, 1) make_setv2(i); // ban đầu tất cả các đỉnh đều là đỉnh cha của nó
    forr(i, 1, m, 1) {
        int type, u, v; inall(type, u, v);
        if (type == 1) {
            union_setsv2(u, v); // gộp 2 note vào 1 cha
        } else {
            // kiểm tra xem 2 note có cùng cha (có liên thông nhau hay không)
            if (find_setv2(u) == find_setv2(v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    TIME;
}
// Tối ưu 2 - Nén đường đi
// Phương pháp tối ưu này nhằm tăng tốc thao tác find_set.
void make_setv3(int v) {
    root[v] = v;
    sz[v] = 1; // Ban đầu tập hợp chứa v có kích cỡ là 1
    h[v] = 0; // Gốc của cây có độ cao là 0
}
int find_setv3(int v) noexcept(true) {
    if (v == root[v]) return v; // Trả về đỉnh v nếu như đỉnh v là gốc của cây
    int p = find_setv3(root[v]); // Đệ quy lên cha của đỉnh v
    root[v] = p; // Nén đoạn từ v lên gốc của cây
    return p;
    // cách viết nhanh
    // return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}
void union_setsv3(int a, int b) {
    a = find_setv3(a);
    b = find_setv3(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); // Đặt biến a là gốc của cây có kích cỡ lớn hơn
        root[b] = a;
        sz[a] += sz[b]; // Cập nhật kích cỡ của cây mới gộp lại
        // if (h[a] == h[b]) h[a]++; // Nếu như hai cây có cùng một độ cao, độ cao của cây mới sau khi gộp sẽ tăng 1
    }
}
void outputv3() noexcept(true) {
    forr(i, 1, n, 1) make_setv3(i); // ban đầu tất cả các đỉnh đều là đỉnh cha của nó
    forr(i, 1, m, 1) {
        int type, u, v; inall(type, u, v);
        if (type == 1) {
            union_setsv3(u, v); // gộp 2 note vào 1 cha
        } else {
            // kiểm tra xem 2 note có cùng cha (có liên thông nhau hay không)
            if (find_setv3(u) == find_setv3(v)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    TIME;
}