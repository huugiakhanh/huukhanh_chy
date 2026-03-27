int father[MAXn][17]; // lưu theo kiểu 2^k => 2^17 <=> xấp xỉ 1e5
int h[MAXn]; // lưu độ sâu từ gốc đến node
vit a[MAXn]; // dánh sách kề
int n, m, k; // n đỉnh, m query,
void dfs(int u, int fu, int deep) { // xâu từ root gốc
    father[u][0] = fu; // cha bậc 0 của u là u
    h[u] = deep; // độ sâu so với gốc là deep
    forr(i, 1, 16, 1) father[u][i] = father[father[u][i - 1]][i - 1]; // Tổ tiên thứ 2^i của u = Tổ tiên thứ 2^(i-1) của (tổ tiên thứ 2^(i-1) của u)
    for (int v : a[u]) { // các đỉnh kề với u trừ gốc của u
        if (v != fu) dfs(v, u, deep + 1); // thì dfs từ đỉnh đó với cha bãc 0 của v là u 
    }
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v); // đưa về cùng 1 độ sâu
    int d = h[u] - h[v]; // tình khoảng cách độ xâu
    forr(i, 0, 16, 1) if (biton(d, i)) u = father[u][i]; // nhảy 2 ^ i để đưa về tổ tiên cùng độ cao với v
    if (u == v) return u; // nếu u = v thì tổ tiền là u
    rfor(i, 16, 0, 1) { // lặp đén khi 2 đỉnh u và v có cùng tổ tiên bậc i
        if (father[u][i] != father[v][i]) {
            u = father[u][i]; v = father[v][i];
        }
    }
    return father[u][0]; // chả về res bậc 0 vì tổ tiên bậc 0 là tổ tiên của i
}
void input() noexcept(true) {
    inall(n, k, m);
    forr(i, 1, n - 1, 1) {
        int u, v; inall(u, v);
        a[u].pub(v); a[v].pub(u);
    }
    dfs(k, k, 0);
    TIME;
}
void output() noexcept(true) {
    while (m--) {
        int s, t; inall(s, t);
        cout << lca(s, t) << '\n';
    TIME;
    }
}