int main() {

    /// KHỞI TẠO:
    bitset<8> a; // khởi tạo bitset a với 8 bit: 00000000
    bitset<8> b(10); // khơi tạo bitset b với 8 bit và mang giá trị của 10: 00001010
    bitset<8> c("10011001"); // khởi tạo bitset c với 8 bit mang giá trị: 10011001

    /// IN bitset:
    cout << a << " " << b << " " << c << '\n'; // in toàn bộ bitset
    int index = 4;
    cout << c[index]; // in ra bit thứ index từ PHẢI sang TRÁI bắt đầu từ 0

    /// XỬ LÍ bitset:
    a[index]; // truy cập bit thứ index
    a[index] = 1; // đôi bit thứ index của a thành 1
    a[index] = 0; // đổi bit thứ index của a thành 0

    /// CÁC CƠ BẢN LỆNH CỦA bitset
    cout << a.size() << '\n'; // in độ dài của bitset
    a.set(); // chuyển toàn bộ bitset a thành 1
    a.set(index); // chuyển bit thứ index thành 1
    a.reset(); // chuyển toàn bộ bitset a thành 0
    a.reset(index); // chuyển bit thứ index thành 0
    a.flip(); // đảo toàn bộ bit của a từ 0 thành 1, 1 thành 0
    a.flip(index); // đảo bit thứ index 0 thành 1, 1 thành 0
    a.count(); // đếm số bit bằng 1

    /// CÁC LỆNH NÂNG CAO HƠN
    a.any(); // kiểm tra có bit nào bằng 1 không? (trả về true / false)
    a.all(); // kiểm tra có phải tất cả các bit đều bằng 1 hay không? (trả về true / false)
    a.to_ulong(); // chuyển bitset thành số
    a.to_string(); // chuyển bitset thành chuỗi

    // VD:
    for (int i = b._Find_first(); i < b.size(); i = b._Find_next(i)) { // duyệt các bit bằng 1
        cout << i << " ";
    }
    /// NOTE:
    // bitset có thể dùng các bitwise
    a | a; // or
    a & a; // and
    a ^ a; // xor
    ~ a; // not
    a << 1; // dịch trái
    a >> 1; // dịch phải

    /// ĐỘ PHỨC TẠP O(n/64)
    return 0;
}