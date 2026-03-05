ll ten[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll base[7] = {2, 3, 5, 7, 11, 13, 17};
vll nt;
ll mulmod(ll a, ll b, ll mod) {
    if (mod == 0) return a * b;
    ll r = 0;
    while (b) {
        if (b & 1) r = (r + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return r;
}
ll powmod(ll a, ll d, ll mod) {
    ll res = 1; a = a % mod;
    while (d) {
        if (d & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        d >>= 1;
    }
    return res;
}
ll ucln(ll a, ll b) {
    while (b) {
        ll uc = b;
        b = a % b; a = uc;
    }
    return a;
}
bl check(ll n) {
    if (n < 2) return false;
    for (ll& c : ten) {
        if (n == c) return true;
        if (n % c == 0) return false;
    }
    ll d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d /= 2;
        s++;
    }
    for (ll a : base) {
        if (a % n == 0) continue;
        ll x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bl ok = true;
        for (int r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                ok = false;
                break;
            }
        }
        if (ok) return false;
    }
    return true;
}
ll fx(ll val, ll n, ll c) { return (mulmod(val, val, n) + c) % n; } // hàm fx: hàm tạo số giả ngẫu nhiên modulo n
ll pollard_rho(ll n) { // thuật toán phân tích thừa số nguyên tố
    // Thuật toán rho dựa trên cơ sở Floyd's cycle-finding algorithm và trên sự đánh giá (còn gọi là vấn đề ngày sinh nhật)
    // rằng hai số x và y đồng dư modulo p với xác suất 0.5 sau khi chọn 1.177 * căn(p).
    // theo đó nếu p là phần tử của n, thì 1 < ucln(abs(x - y), n) <=> p là ước của abs(x - y) và n
    if ((n & 1) == 0) return 2;
    if (n % 3 == 0) return 3;
    while (1) {
        ll c = rand() % (n - 1) + 1;
        ll x = rand() % n;
        ll y = x, d = 1;
        while (d == 1) {
            x = fx(x, n, c);
            y = fx(fx(y, n, c), n, c);
            d = ucln(abs(x - y), n);
        }
        if (d != n) return d;
    }
}
void factorize(ll n) { // gọi đệ quy để lưu thừa nguyên tố của n
    if (n == 1) return; // điều kiện dừng
    if (check(n)) { // nếu n đến cuối dùng là nguyên tố cũng dừng
        nt.pub(n); return;
    }
    ll d = pollard_rho(n);
    factorize(d); // xử lí d là  1 thừ số nguyên tố của n
    factorize(n / d); // xử lí n / d <=> xử lí n / d == 0 trong hàm bth
}
ll n;
void input() noexcept(true) {
    read(n); factorize(n);
    TIMEi;
}
void output() noexcept(true) {
    for (ll p : nt) cout << p << " ";
    TIMEo;
}
