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