// Nghé & Nhím

#define anhnguyet_huukhanh
#ifdef anhnguyet_huukhanh
    #pragma GCC optimize("O2")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("inline")
    #pragma GCC optimize("fast-math")
#endif

#include <bits/stdc++.h>

#define FOR(i, n) for(long long (i) = 0; (i) < (n); ++(i))
#define forr(i, l, r, k) for (long long i = (l); i <= (r); i += (k))
#define rfor(i, r, l, k) for (long long i = (r); i >= (l); i -= (k))
#define for_Cout(a, char) for (auto c : (a)) cout << c << char;
#define TIME cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n"
#define NAME "bai1"

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
inline long long RAND(long long l, long long h) { return uniform_int_distribution<long long>(l, h)(rd); }

typedef short sh;
typedef char cr;
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef bool bl;
typedef long double ldb;

constexpr long long n_test_mn = 10;
constexpr long long n_test_nr = 100;
constexpr long long n_test_mx = 10000;
constexpr long long l_mmx= -1000000;
constexpr long long r_nr = 2000000000;
constexpr long long r_mx = 1000000000000000000;

void make_test() {
    ofstream cout(NAME".inp");
    ll a = RAND(1, r_nr);
    cout << a;
    // in ra test ở đoạn này;

}
int main() {
    // sinh test, ans lấy ở code trâu

    /*              TẠO FOLDER "test" RỒI MỚI CHẠY           */

    system("if not exist test mkdir test");
    for (int anh_nguyet = 1; anh_nguyet <= n_test_nr; ++anh_nguyet) {
        make_test();
        system(NAME"_trau.exe");

        string folder = "TEST\\TEST " + to_string(anh_nguyet);
        system(("if not exist \"" + folder + "\" mkdir \"" + folder + "\"").c_str());


        system(("copy "NAME".inp \"" + folder + "\\"NAME".inp\"").c_str());
        system(("copy "NAME".ans \"" + folder + "\\"NAME".out\"").c_str());

        cout << "Generated test " << anh_nguyet << '\n';
    }
    cout << "Done! " << n_test_nr << " tests in folder TEST\\\n";
    return 0;

    /*              TẠO FOLDER "test" RỒI MỚI CHẠY           */
}
