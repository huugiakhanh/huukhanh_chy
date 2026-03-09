int main() {
   
    long long x = 1991312123;

    /// 1. Đếm bit 1 và 1 (popcount)
    // đếm bit 1:
    cout <<  __builtin_popcount(x) << '\n'; // int (32-bit)
    cout << __builtin_popcountll(x) << '\n'; // long long (64-bit)
    // đếm bit 0:
    cout <<  32 - __builtin_popcount(x) << '\n'; // int (32-bit)
    cout << 64 - __builtin_popcountll(x) << '\n'; // long long (64-bit)

    /// 2. bit thập nhất và bit cao nhất, xóa bit thấp nhất (LSB, MSB)
    cout << (x & -x) << '\n'; // lấy bit thấp nhất
    cout << __builtin_ctz(x) << '\n'; // lấy vị trí bit 1 thấp nhất của int 32 - bit
    cout << __builtin_ctzll(x) << '\n'; // lất vị trí bit 1 thấp nhất của long long 64 - bit
    cout << 31 - __builtin_ctz(x) << '\n'; // lấy vị trí bit 1 cao nhất của int 32 - bit
    cout << 63 - __builtin_ctzll(x) << '\n'; // lất vị trí bit 1 cao nhất của long long 64 - bit
    x &= (x - 1); // xóa bit thấp nhất

    /// 3. kiểm tra bội của 2 (power of 2)
    bool boi2 = (x > 0 && (x & (x - 1)) == 0);
    cout << boi2 << '\n'; // đúng 1 sai 0

    /// 4. duyệt tất cả các bit bằng 1
    while (x) {
        int bit = __builtin_ctz(x);
        x &= x - 1;
    }

    /// 5. đếm bit bằng 1 trong đoạn [l; r]
    int l = 0, r = 5;
    int mask = ((1 << (r - l + 1)) - 1) << l;
    int ans = __builtin_popcount(x & mask);

    /// 6. duyệt các hoán vị của bit x (Submask enumeration)
    int mask0 = 13;
    for (int sub = mask0; sub; sub = (sub - 1) & mask0) {
        cout << bitset<4>(sub) << "\n"; // in ra các hoán vị của mask0 4 bit
    }

    /// 7. dp đêm số mask tức hoán vị con của dp[i] (Superset DP trick)
    int n = 3; int dp[MASK(n)];
    for (int i = 0; i < MASK(n); ++i) dp[i] = i;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                dp[i] += dp[i ^ (1 << j)];
            }
        }
    }
    for (int i = 0; i < MASK(n); ++i) {
        cout << dp[i] << " ";
    }
    // vd: n = 3;
    // a[000]=1
    // a[001]=2
    // a[010]=3
    // a[011]=4
    // a[100]=5
    // a[101]=6
    // a[110]=7
    // a[111]=8
    // <=> dp[111] = dp[111] = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36
    return 0;
}
