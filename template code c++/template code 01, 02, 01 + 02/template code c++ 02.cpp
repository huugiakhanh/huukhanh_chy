// huu khanh chy

// #pragma once
// #pragma GCC optimize("Os")
// #pragma GCC optimize("O2")
// #pragma GCC target("fma")
// #pragma GCC target("sse,sse2")
// #pragma GCC target("sse3,ssse3")
// #pragma GCC target("sse4.1,sse4.2")
// #pragma GCC target("bmi,bmi2")
// #pragma GCC target("popcnt,lzcnt")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2")

// #define anhnguyet_huukhanh
#ifdef anhnguyet_huukhanh
    #pragma GCC optimize("O3")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("inline")
    // #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define FOR(i, l, r) for(long long (i) = (l); (i) < (r); ++(i))
#define forr(i, l, r) for (long long (i) = (l); i <= (r); ++(i))
#define rfor(i, r, l) for (long long (i) = (r); i >= (l); --(i))
#define biton(x, i) (((x) >> (i)) & 1)
#define setbit(x, i) ((x) | (1 << (i)))
#define MASK(i) (1ll << (i))
#define TIMEi cerr << "Time input: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
#define TIMEo cerr << "Time output: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
#define F first
#define S second
#define pub push_back
#define ins insert
#define All(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pli pair<long long, int>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vit vector<int>
#define vbl vector<bool>
#define vstr vector<string>
#define v(data_type) vector<data_type>
#define vvll vector<vector<long long>>
#define vvll vector<vector<long long>>
#define vvit vector<vector<int>>
#define vvbl vector<vector<bool>>
#define umap unordered_map
#define uset unordered_set
#define hmap p_hash_table

template<typename T> bool read_check(T &x) noexcept(true) { x = 0; int sign = 1; int c = getchar(); while (c != EOF && c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == EOF) return false; if (c == '-') { sign = -1; c = getchar(); } while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); } x *= sign; return true; }
template<typename value> void read(value &x) noexcept(true) { x = 0; int sign = 1, c = getchar(); while (c != '-' && (c < '0' || c > '9')) { c = getchar(); } if (c == '-') { sign = -1, c = getchar(); } while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); } x *= sign; }
template<typename value> void write(value x) noexcept(true) {if (x < 0) { putchar('-'); x = -x; } if (x > 9) { write(x / 10); } putchar(char('0' + x % 10)); }
template<typename... value> void in_all(value&... value_of_value) noexcept(true) { ((std::cin >> value_of_value), ...); }
template<typename... value> void out_all(char value_of_char, const value&... value_of_value) noexcept(true) { ((std::cout << value_of_value << value_of_char), ...); }
template<typename... value> void in_all_f(value&... value_of_value) noexcept(true) { ((read(value_of_value)), ...);}
template<typename... value> void out_all_f(char value_of_char, const value&... value_of_value) noexcept(true) { ((write(value_of_value), putchar(value_of_char)), ...); }
template<class T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class T> using ordered_multiset = __gnu_pbds::tree<std::pair<T,int>, __gnu_pbds::null_type, std::less<std::pair<T,int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class X, class Y> bool maximize(X& x, const Y& y) { if (x < y) { x = y; return true; } return false; }
template<class X, class Y> bool minimize(X& x, const Y& y) { if (x > y) { x = y; return true; } return false; }

// của int128
inline bool read128_check(__int128 &x) noexcept(true) { x = 0; __int128 sign = 1; int ch = getchar(); while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) { ch = getchar(); } if (ch == EOF) return false; if (ch == '-') { sign = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); } x *= sign; return true; }
inline __int128 read128() noexcept(true) { __int128 x = 0, f = 1; int ch = getchar(); while (ch != EOF && (ch < '0' || ch > '9')) { if (ch == '-') f = -1; ch = getchar(); } if (ch == EOF) return 0; while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); } return x * f; }
inline void print128(__int128 x) noexcept(true) { if (x < 0) { putchar('-'); x = -x; } if (x > 9) { print128(x / 10); } putchar(x % 10 + '0'); }
inline bool cmp128(__int128 x, __int128 y) { return x > y; }
// của int128

inline void fastIO() noexcept(true) { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
inline void input_file(const std::string& TASK) noexcept(true) { std::string file = TASK + ".INP"; if (FILE* f = fopen(file.c_str(), "r")) { freopen(file.c_str(), "r", stdin); fclose(f); } }
inline void output_file(const std::string& TASK) noexcept(true) { std::string file = TASK + ".OUT"; if (fopen(file.c_str(), "w")) { freopen(file.c_str(), "w", stdout); } }

using namespace std;
using namespace __gnu_pbds;

typedef char cr;
typedef string str;
typedef long long ll;
typedef short sh;
typedef bool bl;
typedef __int128 int128;

inline void input() noexcept(true) {

    TIMEi;
}
inline void output() noexcept(true) {

    TIMEo;
}

int main() {
    fastIO();
    input_file("name"), input();
    output_file("name"), output();
    return 0;
}