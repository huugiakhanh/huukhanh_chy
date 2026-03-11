// hashing hay Hash: A String Matching Algorithm
// Một lớp những bài toán rất được quan tâm trong khoa học máy tính nói chung và lập trình thi cử nói riêng, đó là xử lý xâu chuỗi. Trong lớp bài toán này, người ta thường rất hay phải đối mặt với một bài toán: tìm kiếm xâu chuỗi.
// Cho một đoạn văn bản, gồm m ký tự. Cho một đoạn mẫu, gồm n ký tự. Máy tính cần trả lời câu hỏi: đoạn mẫu xuất hiện bao nhiêu lần trong đoạn văn bản và chỉ ra các vị trí xuất hiện đó.
// Ý tưởng Hashing Thay vì lưu cả chuỗi, ta biến chuỗi thành một số nguyên (hash value)
// abc → hash
// abcd → hash khác
// Nếu 2 chuỗi có hash giống nhau ⇒ có khả năng cao chúng giống nhau.
// hashing có 2 thứ gọi là base(cơ số) và mod(số dư)
// code này cố định gồm
constexpr long long MOD1 = 1000000007LL;
constexpr long long MOD2 = 1000000009LL;
constexpr long long MOD3 = 2147483647LL;
constexpr int base1= 310;
constexpr int base2 = 256;
// 2. Hash tiền tố (Prefix Hash)
// Giúp tính hash substring trong O(1)
// 3. Công thức
// hash[i]=(hash[i − 1] ∗ base + s[i]) % mod
// pow[i] = (pw[i - 1] * base) % mod;
// hash(l, r) = (h[r] − h[l−1] ∗ pow[r - l + 1] % mod + mod) % mod
// ví dụ bài toán Cho 2 xâu A, B độ dài không vượt quá 10^6. Đưa ra những vị trí xuất hiện xâu A trong xâu B.
str n, m;
int nn, nm; // độ dài chuỗi n, m
ll hashn = 0; // lưu hasha
vll hashm(MAXn, 0); // lưu Prefix Hash của m để tìm kiếm
vll pw(MAXn, 1); // lưu bậc của kí tự
void input() noexcept(true) {
    inall(n, m);
    nn = n.size(); nm = m.size();
    TIME;
}
void build() noexcept(true) {
    forr(i, 1, MAXn, 1) { // để an toàn ta tính pw trong trường hợp lớn nhất
        pw[i] = (pw[i - 1] * base1) % MOD1; // chia dư để tránh tràn
    }
    forr(i, 1, nm, 1) {
        hashm[i] = (hashm[i - 1] * base1 + (m[i - 1] - 'a')) % MOD1; // tính tiền tố hashm
    }
    forr(i, 1, nn, 1) {
        hashn = (hashn * base1 + (n[i - 1] - 'a')) % MOD1; // tinh hashn
    }
}
ll gethash(ll l, ll r) {
    return (hashm[r] - hashm[l - 1] * pw[r - l + 1] % MOD1 + MOD1) % MOD1; // cộng thêm mod để tránh tràn
}
void output() noexcept(true) {
    build();
    vll path;
    for (int i = 1; i <= nm - nn + 1; ++i) {
        ll get = gethash(i, i + nn - 1); // lấy hash có độ dài bằng chuỗi n
        if (get == hashn) { // nếu bằng thì đó là xâu con n của m
            path.pub(i);
        }
    }
    cout << path.size() << '\n';
    for_Cout(path, " ");
    TIME;
}
// trường hợp đặt biệt ta cần 2 hashing
ll hash1[MAXn], hash2[MAXn];
ll pw1[MAXn], pw2[MAXn];
void buildv2() {
    pw1[0] = pw2[0] = 1;
    forr(i, 1, MAXn, 1) {
        pw1[i] = pw1[i-1] * base1 % MOD1;
        pw2[i] = pw2[i-1] * base2 % MOD2;
    }
   forr(i, 1, namestring.size(), 1) {
        int val = namestring[i - 1] - 'a' + 1;
        hash1[i] = (hash1[i-1] * base1 + val) % MOD1;
        hash2[i] = (hash2[i-1] * base2 + val) % MOD2;
    }
}
pair<ll,ll> gethash(int l, int r){
    ll h1 = (hash1[r] - hash1[l - 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
    ll h2 = (hash2[r] - hash2[l - 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {h1,h2};
}