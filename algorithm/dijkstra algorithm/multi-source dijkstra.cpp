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



#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

const int INF = 1e18;
const int MOD = 1e9 + 7; // Thường bài đếm đường đi sẽ yêu cầu chia lấy dư

// Cấu trúc đồ thị: vector lưu pair<đỉnh_đích, trọng_số>
vector<vector<pii>> adj;
vector<int> dist_node;
vector<int> cnt;

void multi_source_dijkstra(const vector<int>& sources, int n) {
    dist_node.assign(n + 1, INF);
    cnt.assign(n + 1, 0);
    
    // PQ lưu pair<khoảng_cách, đỉnh>, ưu tiên khoảng cách nhỏ
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // 1. CHỈ DẪN FIX: Đẩy tất cả các đỉnh nguồn vào PQ thay vì 1 đỉnh
    for (int s : sources) {
        dist_node[s] = 0;
        cnt[s] = 1; 
        pq.push({0, s});
    }
    
    while (!pq.empty()) {
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        
        // Bỏ qua nếu đã tìm được đường ngắn hơn trước đó
        if (d > dist_node[u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.fi;
            int w = edge.se;
            
            // 2. CHỈ DẪN FIX: Cập nhật đường đi ngắn hơn hẳn
            if (dist_node[v] > dist_node[u] + w) {
                dist_node[v] = dist_node[u] + w;
                cnt[v] = cnt[u]; // Reset lại số đường đi bằng số đường đi của đỉnh u
                pq.push({dist_node[v], v});
            } 
            // 3. CHỈ DẪN FIX: Nếu tìm thấy đường đi BẰNG khoảng cách ngắn nhất, cộng dồn
            else if (dist_node[v] == dist_node[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; // n đỉnh, m cạnh
    if (!(cin >> n >> m)) return 0;
    
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u, w}); // Mở comment dòng này nếu là đồ thị vô hướng
    }
    
    // Giả sử các đỉnh nguồn là 1, 2, 3
    vector<int> sources = {1, 2, 3}; 
    
    multi_source_dijkstra(sources, n);
    
    // In kết quả số đường đi ngắn nhất đến đỉnh n
    // cout << "Min dist: " << dist_node[n] << " | Num paths: " << cnt[n] << "\n";
    
    return 0;
}

