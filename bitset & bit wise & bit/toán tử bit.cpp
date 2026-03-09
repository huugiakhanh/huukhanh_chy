int main() {

    // TOÁN TỬ BIT

    // 1. toán tử and &
        // Sao chép một bit tới kết quả nếu nó tồn tại trong cả hai toán hạng
        // vd: num & 1  <=> %2
    ll a = 25; // 11001
    ll b = 26;  // 11010
    a &= b;    // 11000
    cout << a << '\n';

    // 2. toán tử or |
        // Sao chép một bit tới kết quả nếu nó tồn tại ít nhất ở một trong hai toán hạng
                    //vd     //vd:
    ll num1 = 8;  // 1000   // 101001
    ll num2 = 9;  // 1001   // 101010
    num1 |= num2; // 1001   // 111011
    cout << num1 << '\n';

    // 3. toán tủ xor ^
        // 0 ^ 0  <=> 0
        // 1 ^ 0  <=> 1
        // 0 ^ 1  <=> 1
        // 1 ^ 1  <=> 0
    ll num3 = 12; // 01100
    ll num4 = 28; // 11100
    num3 ^ num4;  // 10000
    cout << num3 << '\n';

    // 4. toán tử not ~ (đảo bit)
        // chỉ áp dụng cho 1 số
        // vd:
        // 011101 >= 100010
        // 0 => 1
        // 1 => 0
    ll num5 = 90;                  // 1011010
    ll num6 = ~num5; // 111...110100101 (32 bit)
    cout << num6 << '\n';

    // 5. toán tủ dịch trái <<
        // dịch sang trái n bit thì quy ra hệ thập phân là -- NHÂN 2^n
        // ứng dụng tính lũy thừa 2
        // vd 1ll << 9    <=>      2^9
    ll num7 = 99;        //  1100011
    num7 = (num7 << 1);  // 11000110
    cout << num7 << '\n';
    num7 = (num7 << 2);  // 110001100
    cout << num7 << '\n';

    // 6. toán tử dịch phải >>
        // dịch sang trái n bit thì quy ra hệ thập phân là -- CHIA 2^n
    ll num8 = 37;         // 100101
    num8 = (num8 >> 1);   // 010010
    cout << num8;
    return 0;
}

