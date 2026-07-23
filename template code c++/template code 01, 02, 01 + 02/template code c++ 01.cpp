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
#endif

#include <bits/stdc++.h>

#define FOR(i, n) for(long long (i) = 0; (i) < (n); ++(i))
#define forr(i, l, r) for (long long (i) = (l); i <= (r); ++(i))
#define rfor(i, r, l) for (long long (i) = (r); i >= (l); --(i))
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).begin(), (a).end(), greater<long long>())
#define sortt(a, type) sort((a).begin(), (a).end(), type)
#define for_Cout(a, char) for (auto c : (a)) cout << c << char;
#define REV(s) reverse((s).begin(), (s).end())
#define mset(a, valueptr) memset(a, valueptr, sizeof a)
#define biton(x, i) ((x) >> (i) & 1)
#define MASK(i) (1ll << (i))
#define TIME cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
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
#define vvit vector<vector<int>>
#define vvbl vector<vector<bool>>
#define TASK "name"

template<typename... value> void inall(value&... value_of_value) { ((std::cin >> value_of_value), ...); }
template<typename... value> void outall(char value_of_char, const value&... value_of_value) { ((std::cout << value_of_value << value_of_char), ...); }
template<class X, class Y> bool maximize(X& x, const Y& y) { if (x < y) { x = y; return true; } return false; }
template<class X, class Y> bool minimize(X& x, const Y& y) { if (x > y) { x = y; return true; } return false; }

using namespace std;

inline void fastIO() noexcept(true) { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
inline long long gcd_(long long a, long long b) noexcept(true) { while (a != 0) { long long uc = a; a = b % a ; b = uc; } return b; }
inline long long lcd_(long long a, long long b) noexcept(true) { long long res = (a * b) / gcd_(a, b); return res; }
inline long long pow_(long long a, long long b) noexcept(true) { long long res = 1; while (b) { if (b & 1) { res *= a; } a = a * a; b >>= 1; } return res; }
inline long long fac_(long long num) noexcept(true) { unsigned long long res = 1; for (unsigned long long i = 2; i <= num; ++i) res *= i; return res; }
inline long long pow_mod (long long a, long long b, long long mod) noexcept(true) { long long res = 1; a = a % mod; while (b > 0) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
inline long long fac_mod (long long num, long long mod) noexcept(true) { unsigned long long res = 1; for (unsigned long long i = 2; i <= num; ++i) res = (res * i) % mod; return res; }
inline long long inv_(long long num, long long mod) noexcept(true) { return pow_mod(num, mod - 2, mod); }
inline long long ceil_safe(long long num) noexcept(true) { if (num <= 0) { return 0; } long long num_sqrt = (long long)sqrt((double)(num - 1)); while (num_sqrt * num_sqrt > num - 1) { num_sqrt--; } while ((num_sqrt + 1) * (num_sqrt + 1) <= num - 1) { num_sqrt++; } num_sqrt++; return num_sqrt; }
inline long long floor_safe(long long num) noexcept(true) { if (num <= 0) { return 0; } long long num_sqrt = (long long)sqrt((double)num); while (num_sqrt * num_sqrt > num) { num_sqrt--; } while ((num_sqrt + 1) * (num_sqrt + 1) <= num) { num_sqrt++; } return num_sqrt; }

typedef short sh;
typedef char cr;
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef bool bl;
typedef long double ldb;

constexpr long long MOD1 = 1000000007LL;
constexpr long long MOD2 = 1000000009LL;
constexpr long long MOD3 = 2147483647LL;
constexpr long long INF = 1000000000000000000LL;
constexpr int int_0x3f = 1061109567;
constexpr long long ll_0x3f = 4557430888798830399LL;
constexpr int base1= 310;
constexpr int base2 = 256;
constexpr long long MAXn = 100007;

inline void input() noexcept(true) {

    TIME;
}
inline void output() noexcept(true) {

    TIME;
}

int main() {
    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }

    input(), output();
    return 0;
}