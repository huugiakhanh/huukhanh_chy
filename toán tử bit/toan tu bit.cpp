#include <bits/stdc++.h>// huu khanh chy

#define FOR(i, n) for(long long (i) = 0; (i) < (n); (i)++)
#define forthuan(i, l, r, k) for (long long i = (l); i <= (r); i += (k))
#define fornghich(i, r, l, k) for (long long i = (r); i >= (l); i -= (k))
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) sort((a).begin(), (a).end(), greater<long long>())
#define sortype(a, type) sort((a).begin(), (a).end(), type)
#define for_Cout(a, char) for (auto c : (a)) cout << c << char;
#define Auto(c, a) for (auto c : (a))
#define REV(s) reverse((s).begin(), (s).end())
#define F first
#define S second
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>
#define vstr vector<string>
#define v(struct) vector<struct>
#define vvll(a, n, m) vector<vector<long long>>  a((n), vector<long long>(m))

using namespace std;

constexpr long long MOD1 = 1000000007LL;
constexpr long long MOD2 = 1000005LL;

typedef char cr;
typedef string str;
typedef long long ll;
typedef double db;
typedef bool bl;
typedef long double lb;

inline void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
inline long long ucln(long long a, long long b) { while (a != 0) { long long uc = a; a = b % a ; b = uc; } return b; }
inline long long bcnn(long long a, long long b) { long long res = (a * b) / ucln(a, b); return res; }
inline long long luythua(long long a, long long b) { long long res = 1; while (b) { if (b & 1) { res *= a; } a = a * a; b >>= 1; } return res; }
inline long long luythualaydu (long long a, long long b, long long mod) { long long res = 1; a = a % mod; while (b > 0) { if (b & 1) { res = (res * a) % mod; } a = (a * a) % mod; b >>= 1; } return res; }
inline long long giathua(long long num) { long long res = 1; forthuan(i, 2, num, 1) res *= i; return res; }

int main() {
    fastIO();
    if (fopen("TEST.INP", "r")) {
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    }

    // TOÁN TỬ BIT

    // 1. toán tử and &
        // Sao chép một bit tới kết quả nếu nó tồn tại trong cả hai toán hạng
        // vd: num & 1  <=> %2
    ll a = 25; // 11001
    ll b = 26;  // 11010
    a &= b;    // 11000
    cout << a << '\n';

    // 2. toán tử or |
        // Sao chép một bit tới kết quả nếu nó tồn tại ít nhất ở một trong hai toán hạng
                    //vd     //vd:
    ll num1 = 8;  // 1000   // 101001
    ll num2 = 9;  // 1001   // 101010
    num1 |= num2; // 1001   // 111011
    cout << num1 << '\n';

    // 3. toán tủ xor ^
        // 0 ^ 0  <=> 0
        // 1 ^ 0  <=> 1
        // 0 ^ 1  <=> 1
        // 1 ^ 1  <=> 0
    ll num3 = 12; // 01100
    ll num4 = 28; // 11100
    num3 ^ num4;  // 10000
    cout << num3 << '\n';

    // 4. toán tử not ~ (đảo bit)
        // chỉ áp dụng cho 1 số
        // vd:
        // 011101 >= 100010
        // 0 => 1
        // 1 => 0
    ll num5 = 90;                  // 1011010
    ll num6 = ~num5; // 111...110100101 (32 bit)
    cout << num6 << '\n';

    // 5. toán tủ dịch trái <<
        // dịch sang trái n bit thì quy ra hệ thập phân là -- NHÂN 2^n
        // ứng dụng tính lũy thừa 2
        // vd 1ll << 9    <=>      2^9
    ll num7 = 99;        //  1100011
    num7 = (num7 << 1);  // 11000110
    cout << num7 << '\n';
    num7 = (num7 << 2);  // 110001100
    cout << num7 << '\n';

    // 6. toán tử dịch phải >>
        // dịch sang trái n bit thì quy ra hệ thập phân là -- CHIA 2^n
    ll num8 = 37;         // 100101
    num8 = (num8 >> 1);   // 010010
    cout << num8;
    return 0;
}

