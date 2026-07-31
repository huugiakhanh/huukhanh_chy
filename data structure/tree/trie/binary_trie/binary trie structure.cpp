const int MAXNODE = 3000000;
int trie[MAXNODE][2], cnt[MAXNODE], node = 1;

// Khởi tạo Trie, đưa node về 1
inline void init() {
    mset(trie, 0), mset(cnt, 0); node = 1;
}

// Chèn số val vào Trie
inline void insert_(const int& val) {
    int u = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i);
        if (!trie[u][bit]) trie[u][bit] = node++;
        u = trie[u][bit];
        cnt[u]++; // Tăng số lượng số đi qua nhánh này
    }
}

// Kiểm tra số val có trong Trie hay không
inline bl search_(const int& val) {
    int u = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i);
        // Nếu đứt nhánh HOẶC nhánh đó đã bị erase hết (cnt == 0) thì false
        if (!trie[u][bit] || cnt[trie[u][bit]] == 0) return false;
        u = trie[u][bit];
    }
    return true;
}

// Xóa số val khỏi Trie
inline bl erase_(const int& val) {
    if (!search_(val)) return false; // Có tồn tại mới xóa
    int u = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i);
        u = trie[u][bit];
        cnt[u]--; // Rút lại 1 lượt đi qua nhánh này
    }
    return true;
}

// Tìm giá trị max của (val ^ y) với y có trong Trie
inline int get_max_xor(const int& val) {
    int u = 0, res = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i), opp_bit = 1 - bit;
        // Ưu tiên đi ngược bit hiện tại để tạo ra XOR = 1
        if (trie[u][opp_bit] && cnt[trie[u][opp_bit]] > 0) {
            res |= (1 << i); // Bật bit i trong kết quả
            u = trie[u][opp_bit];
        } else {
            // Không có đường ngược thì đành đi đường thuận (XOR = 0)
            u = trie[u][bit];
        }
    }
    return res;
}

// Tìm giá trị min của (val ^ y) với y có trong Trie
inline int get_min_xor(const int& val) {
    int u = 0, res = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i);
        // Ngược lại với max, ưu tiên đi CÙNG bit để tạo ra XOR = 0 triệt tiêu lẫn nhau
        if (trie[u][bit] && cnt[trie[u][bit]] > 0) {
            u = trie[u][bit];
        } else {
            res |= (1 << i);
            u = trie[u][1 - bit];
        }
    }
    return res;
}

// Tìm số nhỏ thứ 'val' trong Trie (val đóng vai trò là K)
inline int get_min_k_in_order(int val) {
    int u = 0, res= 0;
    rfor(i, 30, 0) {
        int left_node = trie[u][0]; // Nhánh chứa bit 0 (các số nhỏ hơn)

        if (left_node && cnt[left_node] > 0) {
            // Nếu lượng số bên trái >= K (val), đáp án chắn chắn nằm bên trái
            if (val <= cnt[left_node]) {
                u = left_node;
            } else {
                // Nếu bên trái không đủ, trừ đi lượng bên trái và rẽ sang phải
                val -= cnt[left_node];
                res |= (1 << i); // Bật bit i vì rẽ nhánh 1
                // [FIXED]: Sửa trie[u][i] thành trie[u][1]
                u = trie[u][1];
            }
        } else {
            // Nhánh trái không có gì, bắt buộc đi nhánh phải
            res |= (1 << i);
            u = trie[u][1];
        }
    }
    return res;
}

// Đếm số lượng số y trong Trie thỏa mãn (x ^ y) < limit
inline int count_xor_less_than(int x, int limit) {
    int u = 0, ans = 0;
    rfor(i, 30, 0) {
        int bit_x = biton(x, i), bit_limit = biton(limit, i);

        if (bit_limit == 1) {
            // Nhánh tạo ra XOR = 0 (tức là nhánh đi theo bit_x).
            // Nếu tạo ra 0 ở bit này thì chắc chắn số đó nhỏ hơn limit -> cộng hết phần tử
            if (trie[u][bit_x]) {
                ans += cnt[trie[u][bit_x]];
            }
            // Bắt buộc đi nhánh tạo ra XOR = 1 để xét tiếp các bit sau
            u = trie[u][1 - bit_x];
        } else {
            // bit_limit là 0, buộc phải đi nhánh tạo ra XOR = 0
            u = trie[u][bit_x];
        }
        if (!u || cnt[u] == 0) break; // Đứt đường thì dừng
    }
    return ans; // Trả về tổng số phần tử thỏa mãn
}

// Đếm số lượng số trong Trie chặt chẽ nhỏ hơn val
inline int get_less_x(int val) {
    int u = 0, ans = 0;
    rfor(i, 30, 0) {
        int bit = biton(val, i);
        if (bit == 1) {
            // Mọi số ở nhánh bit 0 chắc chắn nhỏ hơn -> cộng toàn bộ
            if (trie[u][0]) ans += cnt[trie[u][0]];
            // Đi tiếp vào nhánh 1
            u = trie[u][1];
        } else {
            // Bắt buộc đi nhánh 0 để duy trì hy vọng nhỏ hơn
            u = trie[u][0];
        }
        if (!u || cnt[u] == 0) break;
    }
    return ans;
}






//_________________________________________________________TEST_________________________________________________________
inline void input() noexcept(true) {
    init();
    TIME;
}
inline void output() noexcept(true) {

    vector<int> a = {3, 4, 7, 9};
    for (int x : a) insert_(x);

    cout << "=== 1. TEST INSERT & SEARCH ===\n";
    cout << "Da chen cac so: 3, 4, 7, 9\n";
    cout << "Search 7: " << (search_(7) ? "YES" : "NO") << " (Expected: YES)\n";
    cout << "Search 5: " << (search_(5) ? "YES" : "NO") << " (Expected: NO)\n\n";

    cout << "=== 2. TEST ORDER & COUNT ===\n";
    cout << "So be thu 2: " << get_min_k_in_order(2) << " (Expected: 4)\n";
    cout << "So be thu 4: " << get_min_k_in_order(4) << " (Expected: 9)\n";
    cout << "So luong phan tu < 8: " << get_less_x(8) << " (Expected: 3 - gom 3,4,7)\n\n";

    cout << "=== 3. TEST XOR QUERIES ===\n";
    int x = 5;
    // Giai thich XOR voi 5:
    // 5^3 = 6, 5^4 = 1, 5^7 = 2, 5^9 = 12
    cout << "X = 5. Cac gia tri XOR lan luot la: 6, 1, 2, 12\n";
    cout << "Max XOR voi 5: " << get_max_xor(x) << " (Expected: 12)\n";
    cout << "Min XOR voi 5: " << get_min_xor(x) << " (Expected: 1)\n";

    // So luong phan tu y sao cho (5 ^ y) < 5.
    // Cac gia tri XOR la 6, 1, 2, 12 -> Co 1 va 2 la nho hon 5
    cout << "So phan tu y de (5 ^ y) < 5: " << count_xor_less_than(5, 5) << " (Expected: 2)\n\n";

    cout << "=== 4. TEST ERASE ===\n";
    cout << "Erase so 4: " << (erase_(4) ? "Thanh cong" : "That bai") << '\n';
    cout << "Search 4 sau khi xoa: " << (search_(4) ? "YES" : "NO") << " (Expected: NO)\n";
    cout << "So be thu 2 hien tai: " << get_min_k_in_order(2) << " (Expected: 7)\n";

    // Tap hien tai la: 3, 7, 9.
    // Cac gia tri XOR voi 5: 5^3=6, 5^7=2, 5^9=12. Min la 2.
    cout << "Min XOR voi 5 hien tai: " << get_min_xor(5) << " (Expected: 2)\n";
    TIME;
}
