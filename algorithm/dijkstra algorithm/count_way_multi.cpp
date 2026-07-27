#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<vector<pii>> adj;
vector<int> dist_node; // 1D: K/c ngắn nhất từ TẬP S tới v
vector<int> cnt;       // 1D: Số đường đi ngắn nhất từ TẬP S tới v

void multi_source_dijkstra(const vector<int>& S, int n) {
    dist_node.assign(n + 1, INF);
    cnt.assign(n + 1, 0);
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // 1. CHỈ DẪN FIX: Thao tác này tương đương việc đứng tại "Siêu đỉnh 0", 
    // nhảy một bước trọng số 0 sang toàn bộ các đỉnh trong tập S.
    for (int start_node : S) {
        // Nếu một đỉnh v có thể đi từ nhiều đỉnh trong S với cùng k/c,
        // nó sẽ được cộng dồn nhờ vào việc push tất cả S vào PQ ban đầu.
        dist_node[start_node] = 0;
        cnt[start_node] = 1; 
        pq.push({0, start_node});
    }
    
    while (!pq.empty()) {
        int d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        
        if (d > dist_node[u]) continue;
        
        for (auto edge : adj[u]) {
            int v = edge.fi;
            int w = edge.se;
            
            // 2. CHỈ DẪN FIX: Cập nhật đường đi ngắn hơn
            if (dist_node[v] > dist_node[u] + w) {
                dist_node[v] = dist_node[u] + w;
                cnt[v] = cnt[u]; 
                pq.push({dist_node[v], v});
            } 
            // 3. CHỈ DẪN FIX: Cộng dồn số đường đi
            else if (dist_node[v] == dist_node[u] + w) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
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
    }
    
    // Tập S: Các nhà máy, đồn cảnh sát, hoặc trạm cứu hỏa...
    vector<int> S = {1, 2, 3}; 
    
    multi_source_dijkstra(S, n);
    
    // Kết quả cho ta biết: Từ một trong các trạm 1, 2, 3 đến đỉnh n
    // k/c ngắn nhất là bao nhiêu, và có bao nhiêu đường đi đạt k/c đó.
    // cout << dist_node[n] << " " << cnt[n] << "\n";
    
    return 0;
}