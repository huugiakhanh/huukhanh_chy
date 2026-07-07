vit is_mid[MAXn], ans(MAXn); // lưu các truy vấn lấy k là mid và mảng lưu kết quả
int L[MAXn], R[MAXn]; // lưu L và R để tìm kiêm nhị phân
int n, q; // n là số truy vấn còn q là thời gian max của thay đổi
void input() noexcept(true) {
    forr(i, 1, n) L[i] = 1, R[i] = q;
    TIME;
}
void output() noexcept(true) {
    bl is_continue = true;
    while (is_continue) {
        is_continue = false;
        forr(i, 1, q) is_mid[i].clear(); // reset lại mỗi truy vấn
        forr(i, 1, n) {
            if (L[i] < R[i]) { // nếu chưa dược tính
                is_continue = true; // cho tiếp tục chạy
                ll mid = L[i] + ((R[i] - L[i]) >> 1);
                is_mid[mid].pub(i); // truy vấn thứ i lấy mid là giá trị kiểm tra
            }
        }
        if (is_continue == false) break; // nếu tất cả dược tính rồi thì thoát vì log2(q) nên tối đa chạy log2(q) + 2 lần
        // reset cái data structure đùng dề tính toán
        // vd: memset(fen, 0); meset(seg, 0); ...v...v...
        forr(i, 1, q) {
            // xử lí sự kiện xảy ra
            // update_fen(l, r, w); update_seg(1, 1, q, l, r, w); ...v...v...
            for (int id : is_mid[i]) { // duyệt qua các truy vấn lấy i là mid
                // xử lí điều kiện trong này
                if (/* Đủ điều kiện */ true) {
                    ans[id] = i;
                    R[id] = i - 1;      // Thu hẹp cận trên
                } else {
                    L[id] = i + 1;  // tăng cận dưới vì tại thời điểm i chưa đủ
                }
            }
        }
    }
    forr(i, 1, n) cout << ans[i] << '\n'; // in ra kết quả
    TIME;
}