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
#define pii pair<int, int>
#define pli pair<long long, int>
#define pll pair<long long, long long>
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
const string name = "bai1";  // chỉ cần đổi ở đây

void make_test(const string& name) {
    ofstream fout(name + ".inp");
    // sinh test ở đây chú ý dùng fout chứ không dùng cout
}

void compare_test(const string& name, int n_test) {
    for (int anh_nguyet = 1; anh_nguyet <= n_test; ++anh_nguyet) {
        make_test(name);
        system((name + "_trau.exe").c_str());
        system((name + ".exe").c_str());
        if (system(("fc " + name + ".out " + name + ".ans").c_str()) != 0) {
            cout << "Test " << anh_nguyet << ": WRONG!\n";
            return;
        }
        cout << "Test " << anh_nguyet << ": CORRECT!\n";
    }
}

void create_test(const string& name, int n_test) {
    system("if not exist test mkdir test");
    for (int anh_nguyet = 1; anh_nguyet <= n_test; ++anh_nguyet) {
        make_test(name);
        system((name + "_trau.exe").c_str());
        string folder = "test\\TEST " + to_string(anh_nguyet);
        system(("if not exist \"" + folder + "\" mkdir \"" + folder + "\"").c_str());
        system(("copy " + name + ".inp \"" + folder + "\\" + name + ".inp\"").c_str());
        system(("copy " + name + ".ans \"" + folder + "\\" + name + ".out\"").c_str());
        cout << "Generated test " << anh_nguyet << '\n';
    }
}

int main() {
    // compare_test(name, 100);
    create_test(name, 100);
}
