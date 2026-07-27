#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5 + 5;
int st[4 * MAXN]; // Segment Tree lưu tổng tần số

// Cập nhật điểm: Tăng giá trị tại vị trí pos lên val
void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        st[id] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

// Truy vấn tổng trong đoạn [u, v]
int query(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n + 1);
    vector<int> vals; // Lưu các giá trị để nén tọa độ
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.pb(a[i]);
    }
    
    // 1. CHỈ DẪN CODE: Nén tọa độ
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end()); // Xóa phần tử trùng
    
    int max_val = vals.size(); 
    int inv_count = 0;
    
    // 2. CHỈ DẪN CODE: Duyệt và đếm bằng Seg Tree
    for (int i = 1; i <= n; i++) {
        // Tìm vị trí của a[i] sau khi nén (trả về index từ 1)
        int v = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        
        // Truy vấn số lượng các phần tử > v đã xuất hiện trước đó
        inv_count += query(1, 1, max_val, v + 1, max_val);
        
        // Thêm phần tử hiện tại vào Segment Tree
        update(1, 1, max_val, v, 1);
    }
    
    cout << inv_count << "\n";
    
    return 0;
}