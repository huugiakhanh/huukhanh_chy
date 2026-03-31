/* Ở đây theo template 03 thì define NAME nên ta không cần chuyền name vào nữa có thể dùng luôn cout */
void make_test() {
    ofstream cout(NAME".inp");
    // sinh test ở đây
}

/* Nếu an toàn thì ra chuyền chuỗi là tến bài vào đây và dùng fout thay cho cout */
void make_test(const string& name) {
    ofstream fout(name + ".inp");
    // sinh test ở đây
}

/*
    các kiểu sinh test
     cơ bản việt sinh test là tạo ra input cho chương trình giống yêu cầu đề bài
     dưới đây là cac kiểu sinh test phổ biến
*/

void make_test_array_1D() {
    ofstream cout(NAME".inp");
    ll n = RAND(1, 10);
    cout << n << '\n';
    forr(i, 1, n, 1) {
        cout << RAND(l_mmx, r_nr) << ' ';
    }
    cout << '\n';
}

void make_test_array_2D() {
    ofstream cout(NAME".inp");
    ll n = RAND(1, r_mm), m = RAND(1, r_mm);
    cout << n << ' ' << m << '\n';
    forr(i, 1, n, 1) {
        forr(j, 1, m, 1) {
            cout << RAND(l_mmx, r_nr) << ' ';
        }
        cout << '\n';
    }
}
void make_test_string() {
    ofstream cout(NAME".inp");
    ll n = RAND(1, 20);
    cout << n << '\n';
    forr(i, 1, n, 1) cout << (char)('a' + RAND(0, 25)); // chỉ chữ thường
    cout << '\n';
}
void make_test_graph_undirected() {
    ofstream cout(NAME".inp");
    ll n = RAND(2, 8), m = RAND(1, n * (n - 1) / 2);
    cout << n << ' ' << m << '\n';
    set<pair<ll,ll>> edges;
    ll cnt = 0;
    while (cnt < m) {
        ll u = RAND(1, n), v = RAND(1, n);
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (edges.count({u, v})) continue;
        edges.insert({u, v});
        cout << u << ' ' << v << '\n';
        cnt++;
    }
}
void make_test_graph_directed() {
    ofstream cout(NAME".inp");
    ll n = RAND(2, 8), m = RAND(1, n * (n - 1));
    cout << n << ' ' << m << '\n';
    set<pair<ll,ll>> edges;
    ll cnt = 0;
    while (cnt < m) {
        ll u = RAND(1, n), v = RAND(1, n);
        if (u == v) continue;
        if (edges.count({u, v})) continue;
        edges.insert({u, v});
        cout << u << ' ' << v << '\n';
        cnt++;
    }
}
void make_test_graph_weighted() {
    ofstream cout(NAME".inp");
    ll n = RAND(2, 8), m = RAND(1, n * (n - 1) / 2);
    cout << n << ' ' << m << '\n';
    set<pair<ll,ll>> edges;
    ll cnt = 0;
    while (cnt < m) {
        ll u = RAND(1, n), v = RAND(1, n);
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (edges.count({u, v})) continue;
        edges.insert({u, v});
        ll w = RAND(1, 100);
        cout << u << ' ' << v << ' ' << w << '\n';
        cnt++;
    }
}
void make_test_graph_multi_weight(ll num_weights) {
    ofstream cout(NAME".inp");
    ll n = RAND(2, 8), m = RAND(1, n * (n - 1) / 2);
    cout << n << ' ' << m << '\n';
    set<pair<ll,ll>> edges;
    ll cnt = 0;
    while (cnt < m) {
        ll u = RAND(1, n), v = RAND(1, n);
        if (u == v) continue;
        if (u > v) swap(u, v);
        if (edges.count({u, v})) continue;
        edges.insert({u, v});
        cout << u << ' ' << v;
        forr(k, 1, num_weights, 1) cout << ' ' << RAND(1, 100);
        cout << '\n';
        cnt++;
    }
}
void make_test_segtree() {
    ofstream cout(NAME".inp");
    ll n = RAND(1, 10), q = RAND(1, 20);
    cout << n << ' ' << q << '\n';
    forr(i, 1, n, 1) {
        cout << RAND(1, 100);
        if (i < n) cout << ' ';
    }
    cout << '\n';
    forr(i, 1, q, 1) {
        ll type = RAND(1, 2);
        if (type == 1) {
            // update: 1 idx val
            ll idx = RAND(1, n);
            ll val = RAND(1, 100);
            cout << 1 << ' ' << idx << ' ' << val << '\n';
        } else {
            // query: 2 l r
            ll l = RAND(1, n), r = RAND(1, n);
            if (l > r) swap(l, r);
            cout << 2 << ' ' << l << ' ' << r << '\n';
        }
    }
}
void make_test_query() {
    ofstream cout(NAME".inp");
    ll n = RAND(1, 10), q = RAND(1, 20);
    cout << n << ' ' << q << '\n';
    forr(i, 1, n, 1) {
        cout << RAND(1, 100);
        if (i < n) cout << ' ';
    }
    cout << '\n';
    forr(i, 1, q, 1) {
        ll type = RAND(1, 3);
        if (type == 1) {
            ll idx = RAND(1, n), val = RAND(1, 100);
            cout << 1 << ' ' << idx << ' ' << val << '\n';
        } else if (type == 2) {
            ll l = RAND(1, n), r = RAND(1, n);
            if (l > r) swap(l, r);
            cout << 2 << ' ' << l << ' ' << r << '\n';
        } else {
            ll idx = RAND(1, n);
            cout << 3 << ' ' << idx << '\n';
        }
    }
}