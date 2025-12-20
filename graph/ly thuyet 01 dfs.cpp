// #pragma once // huu khanh chy
#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast", "Os")
// #pragma GCC optimize("inline",)
// #pragma GCC optimize("fast-math",)
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("fma")
// #pragma GCC target("sse,sse2")
// #pragma GCC target("sse3,ssse3")
// #pragma GCC target("sse4.1,sse4.2")
// #pragma GCC target("avx,avx2")
// #pragma GCC target("bmi,bmi2")
// #pragma GCC target("popcnt,lzcnt")

#define TASK "name"
#define FOR(i, n) for(long long (i) = 0; (i) < (n); ++(i))
#define forr(i, l, r, k) for (long long i = (l); i <= (r); i += (k))
#define rfor(i, r, l, k) for (long long i = (r); i >= (l); i -= (k))
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).begin(), (a).end(), greater<long long>())
#define sortt(a, type) sort((a).begin(), (a).end(), type)
#define for_Cout(a, char) for (auto c : (a)) cout << c << char;
#define REV(s) reverse((s).begin(), (s).end())
#define Auto(c, a) for (auto c : (a))
#define mset(a, valueptr) memset(a, valueptr, sizeof a)
#define F first
#define S second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vbl vector<bool>
#define vstr vector<string>
#define v(struct) vector<struct>
#define vvll(a, n, m, value) vector<vector<long long>>  a((n), vector<long long>(m, value))

using namespace std;

constexpr long long MOD1 = 1000000007LL;

typedef char cr;
typedef string str;
typedef long long ll;
typedef double db;
typedef bool bl;
typedef long double ldb;

inline void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
inline long long ucln(long long a, long long b) { while (a != 0) { long long uc = a; a = b % a ; b = uc; } return b; }
inline long long bcnn(long long a, long long b) { long long res = (a * b) / ucln(a, b); return res; }
inline long long luythua(long long a, long long b) { long long res = 1; while (b) { if (b & 1) { res *= a; } a = a * a; b >>= 1; } return res; }
inline long long giathua(long long num) { unsigned long long res = 1; forr(i, 2, num, 1) res *= i; return res; }
inline long long luythualaydu (long long a, long long b, long long mod) { long long res = 1; a = a % mod; while (b > 0) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
inline long long giathualaydu (long long num, long long mod) { unsigned long long res = 1; forr(i, 2, num, 1) res = (res * i) % mod; return res; }

ll n, m;
ll s, t; // đi từ đỉnh s đến t
vector<ll> dothi[1000007];

bl use[1000007]; /// lưu các đỉnh đã đi
ll truyvet[1000007]; /// đến đỉnh k ta đi từ đỉnh nào


void nhap() noexcept(false) {
    cin >> n >> m;
    cin >> s >> t; // nhập s, t
    forr(i, 1, m, 1) {
        ll u, v; cin >> u >> v;
        dothi[u].pb(v);
        dothi[v].pb(u);
    }
}
/// DFS
void dfs(ll u) noexcept(false) {   /// đi từ dỉnh u
    use[u] = true; /// đỉnh u đã đi qua
    for (ll v : dothi[u]) {/// từ u đi đc những đỉnh nào
        if (use[v] == false) {  /// đỉnh v chưa đi đến
            truyvet[v] = u; /// đề đi đến v ta bắt đầu từ u
            dfs(v); /// đệ quy chạy tiếp xem v đến đc đỉnh nào;
        }
    }
    /// kết thúc stack khi từ v không đi đc đỉnh nào nữa
}
/// mang truy vết tùy bài mới cần khái báo

signed main() {

    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    nhap();
    dfs(s); // bắt đầu từ đỉnh s
    use[s] = true; // đỉnh s đã đc dùng
    if (use[t] == false) { // ko có con đg từ s đến t
        cout << -1; return 0;
    }
    vll res; // lưu các đỉnh từ s để đến t
    ll cur = t; // truy vết ngược từ t
    while (cur != s) {
        res.pb(cur);
        cur = truyvet[cur];
    }
    res.pb(s);
    cout << res.size() << '\n';
    REV(res); for_Cout(res, " ");
    return 0;
}

// __attribute__((constructor)) void auto00() { fastIO(); }

// __attribute__((constructor))
// void name() {
//     // ham
// }

// #pragma pack(push, 1)
// struct ten { bien; bien };
// #pragma pack(pop)




