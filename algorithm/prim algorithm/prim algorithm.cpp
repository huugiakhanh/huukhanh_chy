int n, m; // n đỉnh(v), m cạnh(e)
/*Thuật toán Prim tìm cây khung nhỏ nhất (MST) của đồ thị có trọng số.
Ý tưởng cốt lõi: bắt đầu từ một đỉnh bất kỳ, mỗi bước tham
lam chọn cạnh nhỏ nhất nối từ tập đỉnh đã chọn sang đỉnh chưa chọn, cho đến khi bao phủ toàn bộ đồ thị.

Mỗi bước chọn cạnh có trọng số nhỏ nhất nối tập đỉnh đã chọn ↔ chưa chọn
While/For: O(V²) | Priority Queue: O((V+E) log V
*/
struct node {
    int u, v; ll w; // đỉnh u, v có trọng số w
};
v(node) a, MST; // graph a, và cây khung nhỏ nhất MST dạng struct
v(v(pii)) A(MAXn);// dạng danh sách kề cho cách dùng priority queue
vll dis(MAXn); // lưu khoảng cách ngắn nhất đến node
vit root(MAXn); // lưu góc của đỉnh n
vbl inMST(MAXn); // kiểm tra xe đỉnh n có trong cây MST chưa
void prim_for(v(node)& graph, int stu) noexcept(true) { // nhập dồ thị, bắt đầy từ đỉnh stu
    dis[stu] = 0; // bắt đầu từ stu nến khoảng cách băng 0
    for (int iter = 1; iter <= n; ++iter) { // duyệt qua tát cả các đỉnh
        int us = -1; // khai báo đỉnh us = -1;
        for (int i = 1; i <= n; ++i) { // duyệt qua cá đỉnh 1 lần nữa
            if (inMST[i] == false) { // nếu đỉnh i chưa có trong MST
                if (us == - 1 || dis[i] < dis[us]) { // nếu us chưa đuọc gán hoặc khoảng cách từ gốc đến i ngắn hơn đên us
                    us = i; // thi us = i;
                }
            }
        }
        inMST[us] = true; // đáng us dã ở trong cây MST
        // ans += dis[us];
        // Cập nhật key của hàng xóm
        for (node& e : graph) { // duyệt qua đồ thị
            int vs = -1; ll d = 0;
            if (e.u == us) { vs = e.v; d = e.w; } // u là đầu cạnh
            else if (e.v == us) { vs = e.u; d = e.w; } // u là cuối cạnh
            if (vs != -1 && inMST[vs] == false && d < dis[vs]) { // nếu đỉnh v đã được gán, và v chưa có trong cây MST, và khoảng cách đến v dài hơn trọng số gốc
                dis[vs] = d; // gắn khoảng cách thành d
                root[vs] = us; // gốc của vs là us
            }
        }
    }
    ll ans = 0; // tìm đường đi ngắn nhất cuả cây khung
    for (int i = 1; i <= n; ++i) { // duyệt qua các đỉnh
        if (i == stu) continue;  // trư đỉnh nguồn
        ans += dis[i]; // cộng khoảng cách đế đỉnh
        MST.push_back({root[i], i, dis[i]}); // MST thêm gốc của i, i và khoảng cách đến i
    }
    cout << ans << '\n'; // in ra đường đi của cây khung ngán nhất
    for (node& e : MST) { // in ra cây MST
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
}
void prim_while(v(node) graph, int stu) noexcept(true) {
    // dùng while thì thêm 1 biến cnt = 0 và cập nhật sau mỗi là gán us
    // điều kiện dừng là while(cnt < n)
    // còn các bước còn lại tương tự for
}
void prim_priority_queue(v(v(pii))& graph, int stu) noexcept(true) {
    priority_queue<pli, v(pli), greater<pli>> pq; // ưu tiên min heap
    pq.push({0, stu}); ll ans = 0; // thêm đỉnh nguồn stu và khoảng cách bằng 0, ans để lưu kết quả
    while (!pq.empty()) { // điều kiện dừng
        auto [w, u] = pq.top(); pq.pop(); // lấy đỉnh và khoảng cách
        if (inMST[u] == true) continue; // nếu đã có trong cây thì không xét
        inMST[u] = true; ans += w; // đánh u đã có trong cây MST, ans + thêm w
        if (root[u] != -1) { // nếu u có gốc
            MST.pub({root[u], u, w}); // thêm gốc u, u và trọng số w vào MST
        }
        for (auto [v, len] : graph[u]) { // duyệt qua các đỉnh liên thông với u trong đồ thị
            if (inMST[v] == false) { // nếu v chưa có trong đồ thị
                if (dis[v] > len) { // nếu khoảng cách đến v lớn hơn len
                    dis[v] = len; root[v] = u; // khoảng cách đến v = len, gốc của v là u
                    pq.push({len, v}); // thêm v vào queue
                }
            }
        }
    }
    cout << ans << '\n';
    for (node& e : MST) { // in ra cây MST
        cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
    }
}

void input() noexcept(true) {
    inall(n, m);
    forr (i, 1, m, 1) {
        int u, v, w; inall(u, v, w);
        A[u].pub({v, w});
        A[v].pub({u, w});
        a.pub({u, v, w});
    }
    fill(All(dis), INF);
    fill(All(inMST), false);
    fill(All(root), -1);
    TIME;
}
void output() noexcept(true) {
    prim_for(a, 1); cout << '\n';
    fill(All(dis), INF);
    fill(All(inMST), false);
    fill(All(root), -1);
    MST.clear();
    prim_priority_queue(A, 1);
    TIME;
}