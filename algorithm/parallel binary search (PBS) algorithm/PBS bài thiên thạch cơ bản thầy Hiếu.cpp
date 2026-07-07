int n, m, k; vit is_mid[MAXn]; // mảng lưu các truy vấn lấy thời điểm i làm mid để kiểm tra
vit p[MAXn], w_(MAXn); // p lưu các vị trí trạm của quốc gia i, w_ lưu số mẫu thiên thạch cần thu thập
struct query_ {
    int l, r; ll w; // l, r là khoảng rơi, w là số lượng thiên thạch
} queries[MAXn];
ll fen[MAXn], L[MAXn], R[MAXn], ans[MAXn]; // dùng cấu trúc dữ liệu fen tree, L và R để tìm kiêm nhị phân và mảng lưu kết quả

void import_() noexcept(true) {
    inall(n, m); // nhập n quốc gia, m khu vực
    forr(i, 1, m) {
        int p_; cin >> p_; p[p_].pub(i); // p_ là chủ sở hữu của khu vực i, đưa i vào danh sách khu vực của quốc gia p_
    }
    forr(i, 1, n) cin >> w_[i]; // nhập yêu cầu số lượng thiên thạch của từng quốc gia
    cin >> k; // nhập k - tổng số trận mưa thiên thạch (thời gian max của thay đổi)
}
ll query(int i) { // tính tổng lượng thiên thạch rơi tại 1 vị trí (point query)
    ll res = 0;
    for (; i >= 1; i -= (i & -i)) {
        res += fen[i];
    }
    return res;
}
void update(int i, ll w) { // update lượng thiên thạch trên Fenwick Tree
    for (; i <= m; i += (i & -i)) {
        fen[i] += w;
    }
}
void process_update(int l, int r, ll w) { // xử lý cập nhật mảng vòng (circular range update)
    if (l <= r) {
        update(l, w); update(r + 1, -1 * w); // cập nhật đoạn [l, r] bình thường
    } else {
        update(l, w); update(m + 1, -1 * w); // nếu bị lố qua mảng, cập nhật đoạn cuối [l, m]...
        update(1, w); update(r + 1, -1 * w); // ...và vắt sang đoạn đầu [1, r]
    }
}
void deal_with() {
    forr(i, 1, n) L[i] = 1, R[i] = k; // khởi tạo khoảng tìm kiếm nhị phân cho n quốc gia

    forr(i, 1, k) {
        inall(queries[i].l, queries[i].r, queries[i].w); // lưu lại k sự kiện
    }

    bl is_continue = true;
    while (is_continue) {
        is_continue = false;
        forr(i, 1, k) is_mid[i].clear(); // reset danh sách chờ (queue) ở mỗi vòng lặp log(k)

        forr(i, 1, n) {
            if (L[i] <= R[i]) { // nếu quốc gia i chưa chốt được thời điểm duy nhất
                is_continue = true; // cho tiếp tục chạy log tiếp theo
                ll mid = L[i] + ((R[i] - L[i]) >> 1); // lấy thời điểm giữa (mid)
                is_mid[mid].pub(i); // truy vấn thứ i (quốc gia i) lấy mid là thời điểm cần kiểm tra
            }
        }
        if (is_continue == false) break; // nếu tất cả đều L > R thì thoát
        mset(fen, 0); // reset data structure cho lần sweep-line (mô phỏng) mới

        forr(i, 1, k) { // bắt đầu mô phỏng thời gian từ 1 đến k
            // xử lí sự kiện mưa thiên thạch xảy ra tại thời điểm i
            process_update(queries[i].l, queries[i].r, queries[i].w);
            // duyệt qua các quốc gia lấy thời điểm i làm mid để test
            for (int id : is_mid[i]) {
                ll total = 0;
                for (int pos : p[id]) { // gom thiên thạch từ tất cả khu vực của quốc gia id
                    total += query(pos);
                    if (total >= w_[id]) break; // Mẹo tối ưu an toàn: ngắt sớm để tổng không bị tràn limit long long
                }
                // kiểm tra điều kiện
                if (total >= w_[id]) { // nếu đạt hoặc vượt chỉ tiêu tại thời điểm i (mid)
                    ans[id] = i; // ghi nhận đáp án tạm thời
                    R[id] = i - 1; // thu hẹp cận trên xuống i - 1 vì đáp án có thể còn nhỏ hơn
                } else {
                    L[id] = i + 1; // thời điểm i vẫn chưa đủ, đáp án phải nằm ở tương lai (tăng cận dưới)
                }
            }
        }
    }
    forr(i, 1, n) { // in kết quả
        if (ans[i] == 0) cout << "-1\n"; // nếu = 0 tức là mô phỏng đến k vẫn không thu đủ số lượng
        else cout << ans[i] << '\n'; // in ra thời điểm hoàn thành sớm nhất
    }
}