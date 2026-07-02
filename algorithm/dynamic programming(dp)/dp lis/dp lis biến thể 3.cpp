struct stone {
    int a, b, c, idx;
    void inport_() {
        cin >> a >> b >> c;
    } void analyze() {
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        c = arr[0], a = arr[1], b = arr[2];
    }
};
bl cmp(const stone& l, const stone& r) {
    if (l.a != r.a) return l.a > r.a;
    return l.b > r.b;
}
int n; vll dp(MAXn); v(stone) arr(MAXn);
void input() noexcept(true) {
    cin >> n; forr(i, 1, n) arr[i].inport_(), arr[i].analyze(), arr[i].idx = i;
    sort(arr.begin() + 1, arr.begin() + n + 1, cmp); // có sắp xếp vì có thể chọn không quan trọng vị trí ban đầu
    TIME;
}
void output() noexcept(true) {
    //b1: dp[i] là max giá trị đến i
    forr(i, 1, n) {
        dp[i] = arr[i].c; //b3: trường hợp cơ sở chỉ mình nó nên dp[i] = chính giá trị cần tính của a[i]
        forr(j, 1, i - 1) { //b2: dp[i] được tính từ dp[j] từ 1 đến i - 1
            if (arr[j].a >= arr[i].a && arr[j].b >= arr[i].b) { // điều kiện để chọn đc dp[j]
                dp[i] = max(dp[i], dp[j] + arr[i].c); // dp[i] = max(dp[i], dp[j] + cost);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()); // kết quả chưa chắc đã là vị trí đá cuối cùng
    TIME;
}
