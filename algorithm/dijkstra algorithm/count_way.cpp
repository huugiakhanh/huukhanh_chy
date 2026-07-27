#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2005; // Tùy chỉnh theo giới hạn N của bài

vector<vector<pii>> adj;

// 1. CHỈ DẪN FIX: Khai báo mảng 2 chiều toàn cục để tránh tràn stack
int dist_node[MAXN][MAXN];
int cnt[MAXN][MAXN];

// Hàm chạy Dijkstra với gốc là đỉnh 'start'
void dijkstra(int start, int n) {
    // 2. CHỈ DẪN FIX: Khởi tạo mảng 2 chiều chỉ riêng cho hàng 'start'
    for (int i = 1; i <= n; i++) {
        dist_node[start][i] = INF;
        cnt[start][i] = 0;
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // Bắt đầu từ 1 đỉnh duy nhất, thay vì ném một lúc nhiều đỉnh
    dist_node[start][start] = 0;
    cnt[start][start] = 1;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        
        if (d > dist_node[start][u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.fi;
            int w = edge.se;
            
            // 3. CHỈ DẪN FIX: Các biểu thức đều dùng mảng 2 chiều với index đầu là 'start'
            if (dist_node[start][v] > dist_node[start][u] + w) {
                dist_node[start][v] = dist_node[start][u] + w;
                cnt[start][v] = cnt[start][u]; 
                pq.push({dist_node[start][v], v});
            } 
            else if (dist_node[start][v] == dist_node[start][u] + w) {
                cnt[start][v] = (cnt[start][v] + cnt[start][u]) % MOD;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; 
    if (!(cin >> n >> m)) return 0;
    
    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u, w}); // Nếu đồ thị vô hướng
    }
    
    // 4. CHỈ DẪN FIX: Gọi Dijkstra N lần để tính cho mọi cặp đỉnh
    for (int i = 1; i <= n; i++) {
        dijkstra(i, n);
    }
    
    // Truy xuất thử: Khoảng cách ngắn nhất từ u đến v
    // int u = 1, v = n;
    // cout << "Min dist from " << u << " to " << v << ": " << dist_node[u][v] << "\n";
    // cout << "Paths count: " << cnt[u][v] << "\n";
    
    return 0;
}