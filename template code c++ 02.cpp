// #pragma once // huu khanh chy
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast", "Os")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
#pragma GCC optimize("inline",)
// #pragma GCC optimize("fast-math",)
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("fma")
#pragma GCC target("sse,sse2")
// #pragma GCC target("sse3,ssse3")
#pragma GCC target("sse4.1,sse4.2")
#pragma GCC target("avx,avx2")
#pragma GCC target("bmi,bmi2")
// #pragma GCC target("popcnt,lzcnt")

#define FOR(i, n) for(long long (i) = 0; (i) < (n); ++(i))
#define forr(i, l, r, k) for (long long i = (l); i <= (r); i += (k))
#define rfor(i, r, l, k) for (long long i = (r); i >= (l); i -= (k))
#define biton(x, i) ((x) >> (i) & 1)
#define MASK(i) (1ll << (i))
#define TIMEi cerr << "Time input: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
#define TIMEo cerr << "Time output: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
#define F first
#define S second
#define pub push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vit vector<int>
#define vbl vector<bool>
#define vstr vector<string>
#define v(struct) vector<struct>
#define vvll vector<vector<long long>>
#define umap unordered_map
#define uset unordered_set

template<typename value> void read(value &x) noexcept(true) { x = 0; int sign = 1, c = getchar(); while (c != '-' && (c < '0' || c > '9')) { c = getchar(); } if (c == '-') { sign = -1, c = getchar(); } while (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = getchar(); } x *= sign; }
template<typename value> void write(value x) noexcept(true) {if (x < 0) { putchar('-'); x = -x; } if (x > 9) { write(x / 10); } putchar(char('0' + x % 10)); }
template<typename... value> void inall(value&... valueofvalue) noexcept(true) { ((std::cin >> valueofvalue), ...); }
template<typename... value> void outall(char valueofchar, const value&... valueofvalue) noexcept(true) { ((std::cout << valueofvalue << valueofchar), ...); std::cout << valueofchar; }
template<typename... value> void inallf(value&... valueofvalue) noexcept(true) { ((read(valueofvalue)), ...);}
template<typename... value> void outallf(char valueofchar, const value&... valueofvalue) noexcept(true) { ((write(valueofvalue), putchar(valueofchar)), ...); }

// của int128
__int128 read128() { __int128 x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); } while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); } return x * f; }
void print128(__int128 x) noexcept(true) { if (x < 0) { putchar('-'); x = -x; } if (x > 9) { print128(x / 10); } putchar(x % 10 + '0'); }
bool cmp128(__int128 x, __int128 y) { return x > y; }
// của int128

inline void fastIO() noexcept(true) { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); }
inline void inputfile(const std::string& TASK) noexcept(true) { std::string file = TASK + ".INP"; if (FILE* f = fopen(file.c_str(), "r")) { freopen(file.c_str(), "r", stdin); fclose(f); } }
inline void outputfile(const std::string& TASK) noexcept(true) { std::string file = TASK + ".OUT"; if (fopen(file.c_str(), "w")) { freopen(file.c_str(), "w", stdout); } }

using namespace std;

typedef char cr;
typedef string str;
typedef long long ll;
typedef bool bl;
typedef __int128 int128;

void input() noexcept(true) {

    TIMEi;
}
void output() noexcept(true) {

    TIMEo;
}

int main() {
    fastIO();
    inputfile("name"), input();
    outputfile("name"), output();
    return 0;
}