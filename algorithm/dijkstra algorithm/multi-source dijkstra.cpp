int n, m;
vector<pii> a[100005]; // adj[u] = {v, weight}
long long dist[100005];
// Truyền vào danh sách các đỉnh nguồn (sources)
inline void multiDijkstra(const vector<int>& sources) {
    // priority_queue min-heap
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    // 1. Khởi tạo mọi đỉnh là vô cực
    forr(i, 1, n) {
        dist[i] = INF;
    }
    // 2. Bỏ TẤT CẢ các đỉnh nguồn vào hàng đợi và set dist = 0
    for(int src : sources) {
        dist[src] = 0;
        pq.push({0, src});
    }
    // 3. Vòng lặp Dijkstra tiêu chuẩn
    while(!pq.empty()) {
        ll d_u = pq.top().first;
        int u = pq.top().second; pq.pop();
        // Bỏ qua nếu có đường đi khác tối ưu hơn đã cập nhật
        if(d_u > dist[u]) continue;
        // Duyệt các đỉnh kề
        for(auto edge : a[u]) {
            int v = edge.first;
            int w = edge.second;
            // Cập nhật đường đi (Relaxation)
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

// Cách gọi mẫu:
// vector<int> sources = {2, 5, 8}; // Các đỉnh có trạm cảnh sát
// multiDijkstra(sources);