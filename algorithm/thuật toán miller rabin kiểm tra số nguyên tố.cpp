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
#define All(x) (x).begin(), (x).end()
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

ll ten[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // 10 số nguyên tố đầu tiêm để check nhanh
int base1[3] = {2, 7, 61}; // hệ cơ số cho kiểm tra <= 1e9
ll base2[7] = {2, 3, 5, 7, 11, 13, 17}; // hệ cơ số cho kiểm tra <= 1e18
ll base3[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}; // hệ cơ số cho kiểm tra <= 1e18 như nhanh và chắc chắn nhất

ll mulmodv1(ll a, ll b, ll mod) { // hàm nhân chia dư để tránh tràn
    return (int128) a * b % mod; // int128 để trường hợp xấu nhất ko bị tràn
}
ll mulmodv2(ll a, ll b, ll mod) { // hàm nhân chia dư v2 ko dùng int128, dùng cho máy chấm themis, và các phiên bản c++ thấp
    long double x = (long double) a * b; // tính tích để ko bị tràn
    ll t = (ll)(x / mod); // tính thương của a * b cho mod
    ll m = x - t * mod; // tính du bằng các lấy tích từ thương nhân số chia
    // vì long double có sai số nên t cần
    if (m < 0) m += mod;
    if (m >= mod) m -= mod;
    return m;
}
ll mulmodv3(ll a, ll b, ll mod) { // hàm nhân chi dư v3 dùng nhân ấn độ
    if (mod == 0) return a * b;
    ll r = 0; // lưu res
    while (b) {
        if (b & 1) r = (r + a) % mod; // nếu b lẻ thì res += a và chia dư
        a = (a + a) % mod; // 2 * a chi dư để tính tiếp
        b >>= 1; // b / 2
    }
    return r;
}
ll powmodv1(ll a, ll b, ll mod) { // lũy thừa nhị phân chia dư với n <= 1e18 như có 1 sai số nhất định
    ll res = 1; a %= mod; // tiền xử lí
    while (b) {
        if (b & 1) res = mulmodv1(res, a, mod); // dùng mulmodv1 thanh * để tránh tràn
        a = mulmodv1(a, a, mod); // như trên
        b >>= 1;
    }
    return res;
}
ll powmodv2(ll a, ll b, ll mod) { // lũy thừa nhị phân chia dư bth với n <= 1e9 dùng an toàn nhất
    ll res = 1; a %= mod; // tiền xử lí
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod; // như trên
        b >>= 1;
    }
    return res;
}
ll powmodv3(ll a, ll b, ll mod) { // lũy thừa nhị phân chia dư với nhân ấn độ
    ll res = 1; a %= mod; // tiền xử lí
    while (b) {
        if (b & 1) res = mulmodv3(res, a, mod); // dùng mulmodv3 kiểu nhân ấn độ
        a = mulmodv3(a, a, mod); // như trên
        b >>= 1;
    }
    return res;
}
bl millerrabin(ll n) {
    if (n < 2) return false;
    for (auto& c : ten) { // kiểm tra trước nếu n là bội của 1 hoặc nhiều số tron 10 số nguyên tố đầu tiên
        if (n == c) return true;
        if (n % c == 0) return false;
    }
    ll d = n - 1, s = 0;
    // ta có mọi số ta đều biểu diễn ở dạng n - 1 = d * 2^s
    while (!(d & 1)) { // duyện đến khi d lẻ
        s++; // mũ của 2
        d >>= 1; // chia đôi mỗi lần
    }
    // theo đó cách kiêm tra tra là sử dụng số chính phương dạng x^2
    // vì số nguyên tố luôn & 1 đc (t trừ 2) nên ta áp dụng định lí fermat nhỏ a ^ (n - 1) ≡ 1 (mod n)
    // khi này t  kiểm tra như sau cơ số base ^ (n - 1) với n là số cần kiểm tra
    // base ^ (n - 1) <=> base ^ (d * 2 ^ s) <=> base ^ d * base ^ (2 ^ s)
    // ta kiểm ra base ^ d % n vì là số chính phương nên ta kiểm tra trường hơp ≡ 1 hoặc n - 1 đúng thì loại sai thì duyệt cơ số tiếp theo
    // nếu khác 1 và n - 1 ta xỉ lí đến  base ^ (2 ^ s) tức xử lí 2 ^ s
    // ở đây t kiểm tra từ bâc s từ 1 đến s - 1
    // nếu base ^ (2 ^ s) ≡ với 1 hoặc n - 1 tiếp túc thì n là tạm là số nguyên tố mà kiểm tra thêm cơ số khác
    // trường hợp chạy hết các base và toàn bộ đều ≡ với 1 hoặc n - 1 thì n là số nguyên tố
    for (auto& a : base2) {
        if (a > n) continue;
        ll x = powmodv1(a, d, n); // kiểm tra từ cơ số (a ^ d) % n nếu == 1 hoặc == -1 (n - 1) thì
        if (x == 1 || x == n - 1) continue; // kiểm tra  base ^ d
        // trường hợp dồng dư khác 1 và n - 1
        // xét trường hợp base ^ (2 ^ s)
        bl ok = true;
        for (int k = 1; k < s; ++k) { // duyệt bậc của s
            x = mulmodv1(x, x, n); // base ^ d * base ^ d
            // nếu trong s lần có 1 lần ≡ 1 hoặc n - 1 loại
            if (x == 1 || x == n - 1) {
                ok = false; break; // tức n tạm là số nguyên tố cần kiêm tra thêm
            }
        }
        if (ok) return false; // nếu ok chx bị thay đổi thành false tức x ko ≡ với 1 / n - 1 thì ko là số nguyên tố
   }
    return true;
}
ll n;
void input() noexcept(true) {
    cin >> n;
    TIMEi;
}
void output() noexcept(true) {
    cout << (millerrabin(n) ? "YES" : "NO");
    TIMEo;
}

int main() {
    fastIO();
    inputfile("name"), input();
    outputfile("name"), output();
    return 0;
}