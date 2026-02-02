// #pragma once // huu khanh chy
#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast", "Os")
// #pragma GCC optimize("O2")
// #pragma GCC optimize("O3")
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

#define FOR(i, n) for(long long (i) = 0; (i) < (n); ++(i))
#define forr(i, l, r, k) for (long long i = (l); i <= (r); i += (k))
#define rfor(i, r, l, k) for (long long i = (r); i >= (l); i -= (k))
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).begin(), (a).end(), greater<long long>())
#define sortt(a, type) sort((a).begin(), (a).end(), type)
#define for_Cout(a, char) for (auto c : (a)) cout << c << char;
#define REV(s) reverse((s).begin(), (s).end())
#define mset(a, valueptr) memset(a, valueptr, sizeof a)
#define biton(x, i) ((x) >> (i) & 1)
#define MASK(i) (1ll << (i))
#define TIME cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
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
#define TASK "name"

template<typename... value> void inall(value&... valueofvalue) { ((std::cin >> valueofvalue), ...); }
template<typename... value> void outall(char valueofchar, const value&... valueofvalue) { ((std::cout << valueofvalue << valueofchar), ...); std::cout << valueofchar; }

using namespace std;

constexpr long long MOD1 = 1000000007LL;
constexpr long long MOD2 = 1000000009LL;
constexpr long long INF = 1000000000000000000LL;

typedef char cr;
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
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

void input() noexcept(true) {

    TIME;
}
void output() noexcept(true) {
    
    TIME;
}

signed main() {
    fastIO();
    if (fopen(TASK".INP", "r")) {
        freopen(TASK".INP", "r", stdin);
        freopen(TASK".OUT", "w", stdout);
    }


    input(), output();
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
