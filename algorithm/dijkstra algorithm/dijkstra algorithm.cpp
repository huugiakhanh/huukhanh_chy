int n, m, s, t;
// n: số node
// m: số đường đi
// s: đỉnh bắt đầu
// t: đỉnh cần đến
vector<pair<int, int>> graph[MAXn]; // khai báo danh sách kề
vector<ll> dis(MAXn); // lưu khoảng cách đến đỉnh thứ n;
vector<int> trace(MAXn, -1); // lưu từ s đến t cần đi qua các đỉnh nào
vector<int> path; // mảng lưu đg đi từ s đến t;
void input() noexcept(true) {
    cin >> n >> m >> s >> t;
    fill(All(dis), INF);
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        // đỉnh u đến v và v đến u có trọng số là w
        graph[u].pub({v, w});
        graph[v].pub({u, w});
    }
    TIME;
}
void output() noexcept(true) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // hành chờ ưu tên theo min heap
    dis[s] = 0; // bắt đầu từ s nên khoảng cách bằng 0
    pq.push({0, s}); // thêm khoảng cách 0 bà node s vào hành đợi
    while (!pq.empty()) { // duyệt đến ghết queue
        auto [d, u] = pq.top(); pq.pop(); // lấy node và dis bé nhất ra
        if (d != dis[u]) continue; // nếu khoảng cách d đến đỉnh node vấn là INF thì ko cần tính
        for (auto [v, w] : graph[u]) { // duyệt qua các node có thể đi từ node u
            if (dis[v] > dis[u] + w) { // nếu khoảng cách từ node trc đến v lớn hơn node trc đến u + w(u, v) là trọng số từ u đến v
                dis[v] = dis[u] + w; // dặt khoảng cách từ node trc đến v là w bé hơn
                trace[v] = u;
                pq.push({dis[v], v}); // thêm khoảng cách v và node v vào pq;
            }
        }
    }
    cout << dis[t] << '\n'; // in ra trọng số bé nhất từ s đến t;
    for (int v = t; v != -1; v = trace[v]) { // duyệt ngược từ s đến t đến khi bằng -1 thì dừng
        path.pub(v); // thêm node v vào mảng
    }
    REV(path); // đảo laj mảng path vì đgng đi ngược lại về t
    for_Cout(path, ' '); // in mảng path
    TIME;
}