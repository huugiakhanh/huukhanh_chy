const int MAXNODE = 1000000; // độ dài tối đa của chuỗi
int trie[MAXNODE][26]; // trie[u][c] = nút con theo ký tự c
bool is_end[MAXNODE];  // nếu true là kết thúc tại node này còn false là không
int cnt[MAXNODE];     // số chuỗi đi qua / kết thúc tại nút
int node = 1;         // số nút hiện có (gốc = 0)

inline void init() {
    mset(trie, 0); // giá trị ban đàu bằng 0
    mset(cnt, 0); // giá trị ban đầu bằng 0
    mset(is_end, false); // giá trị ban đầu là false
    node = 1;
}
inline void insert_(const str& s) {
    int u = 0; // gốc
    for (cr ch : s) { // duyệt s
        int c = ch - 'a'; // lấy max ascii
        if (!trie[u][c]) trie[u][c] = node++; // tăng node
        u = trie[u][c]; //
        cnt[u]++;
    }
    is_end[u] = true;
}

inline bool search(const str& s) {
    int u = 0; // gốc
    for (cr ch : s) {
        int c = ch - 'a';
        if (!trie[u][c]) return false; // không có nhánh
        u = trie[u][c];
    }
    return is_end[u];
    // return true; // đã từng được chèn
}

inline bl erase_(const str& s) {
    if (!search(s)) return false; // nếu s không là tiền tồ thì ko xóa được
    int u = 0;
    for (cr ch : s) {
        int c = ch - 'a';
        u = trie[u][c]; // duyệt các node có s là tiền tố
        cnt[u]--; // giảm đi số chuỗi đi qua node
    }
    is_end[u] = false; // xóa thì node u không là node kết thúc nữa
    return true;
}

inline int count_prefix(const str& s) {
    int u = 0; // bắt đầu tù đỉnh nguồn
    for (cr ch : s) {
        int c = ch - 'a';
        if (!trie[u][c]) return 0; // nếu ko có nhánh thì s không là tổ tiên của chuỗi nào
        u = trie[u][c]; // nếu có thì duyệt u xuống sâu hơn
    }
    return cnt[u]; // số chuỗi kết thúc tại node u
}

inline void dfs(int u, str now_s) {
    if (is_end[u] == true) { // nếu node u là node cuối
        cout << now_s << '\n'; // in ra xâu lấy s là tiền tố
    } forr(i, 0, 25) { // duyệt theo 25 chứ cái xem có chữ cái nào
        if (trie[u][i] && cnt[trie[u][i]] > 0) {
            dfs(trie[u][i], now_s + (cr)(i + 'a')); // dfs tiếp từ trie[u][i] mới, và + thêm kí tức mới
        }
    }
} inline void search_child(const str& s) {
    int u = 0; bl is_ancestor = true; // kiểm tra xem s có là tiền tố sâu nào không
    // giống bước search
    for (cr ch : s) {
        int c = ch - 'a';
        if (!trie[u][c]){
            is_ancestor = false;
            break;
        } u = trie[u][c];
    }
    if (is_ancestor == false) { // nếu s không là tiền tố của cái nào thì kết thúc
        cout << s << " is't ancestor" << '\n';
        return;
    }
    cout << s << ": \n"; // nếu là tiền tố
    dfs(u, s); // tìm nhưng chuỗi lấy s là tiền tố
}

inline str get_k_in_order(int k) {
    int u = 0; str res = "";
    while (k > 0) {
        if (is_end[u]) {
            k--; // nếu node này là 1 từ hoàn chỉnh, trừ k đi 1
            if (k == 0) return res; // nếu k về 0 nghĩa là từ hoàn chỉnh này chính là đáp án
        }
        forr(i, 0, 25) {
            int nxt = trie[u][i];
            if (nxt && cnt[nxt] > 0) {
                // Nếu k nhỏ hơn hoặc bằng số lượng chuỗi ở nhánh này -> kết quả NẰM TRONG nhánh này
                if (k <= cnt[nxt]) {
                    res += (cr)(i + 'a');
                    u = nxt; // chui xuống nhánh này
                    break;   // thoát vòng forr để duyệt tiếp ở độ sâu mới
                } else {
                    // Nếu nhánh này không đủ chứa k, trừ đi lượng chuỗi nhánh này và thử chữ cái tiếp theo (chữ lớn hơn)
                    k -= cnt[nxt];
                }
            }
        }
    }
    return res;
}

inline str get_longest_ancestor() {
    int u = 0; str res = "";
    while (true) {
        int branch_cnt = 0, next_node = -1, next_cr = -1;
        // Bước 1: Quét 26 chữ cái để xem node hiện tại chẻ ra làm mấy nhánh
        forr(i, 0, 25) {
            int nxt = trie[u][i];
            if (nxt && cnt[nxt] > 0) {
                branch_cnt++;
                next_node = nxt;
                next_cr = i;
            }
        }
        // Dừng lại nếu:
        // 1. Không có nhánh nào hoặc có nhiều hơn 1 nhánh (tách ra thành nhiều từ khác nhau)
        // 2. Node hiện tại là điểm kết thúc của một từ ngắn hơn
        if (branch_cnt != 1 || is_end[u]) break;
        // Bước 2: Đi xuống nhánh duy nhất
        res += (cr)(next_cr + 'a');
        u = next_node;
    }
    return res;
}


//___________________________________________________TESTING___________________________________________________

inline void input() noexcept(false) {
    init();
    TIME;
}
inline void output() noexcept(true) {

    vector<str> words = {"app", "apple", "application", "bat", "batman", "banana", "cat"};
    for (const str& w : words) {
        insert_(w);
    }
    cout << "Da chen cac tu: app, apple, application, bat, batman, banana, cat\n";
    cout << "Search 'apple': " << (search("apple") ? "YES" : "NO") << " (Expected: YES)\n";
    cout << "Search 'applet': " << (search("applet") ? "YES" : "NO") << " (Expected: NO)\n";
    cout << "Search 'bat': " << (search("bat") ? "YES" : "NO") << " (Expected: YES)\n\n";

    cout << "=== 2. TEST COUNT PREFIX & SEARCH CHILD ===\n";
    cout << "So tu co tien to 'app': " << count_prefix("app") << " (Expected: 3)\n";
    cout << "So tu co tien to 'ba': " << count_prefix("ba") << " (Expected: 3 - bat, batman, banana)\n";
    cout << "So tu co tien to 'z': " << count_prefix("z") << " (Expected: 0)\n";
    cout << "-> Danh sach cac tu co tien to 'bat':\n";
    search_child("bat");
    cout << '\n';

    cout << "=== 3. TEST K-TH STRING ===\n";
    cout << "Thu tu tu dien cua Trie hien tai:\n";
    cout << "1. app\n2. apple\n3. application\n4. banana\n5. bat\n6. batman\n7. cat\n";
    cout << "Tim chuoi thu 3: " << get_k_in_order(3) << " (Expected: application)\n";
    cout << "Tim chuoi thu 6: " << get_k_in_order(6) << " (Expected: batman)\n";
    cout << "Tim chuoi thu 1: " << get_k_in_order(1) << " (Expected: app)\n\n";

    cout << "=== 4. TEST LONGEST ANCESTOR (LCP) ===\n";
    cout << "LCP hien tai (nhieu tu khac tien to o goc): '" << get_longest_ancestor() << "' (Expected: rong)\n";

    // Reset Trie de test LCP cu the hon
    init();
    insert_("flight");
    insert_("flow");
    insert_("flower");
    cout << "-> Da reset Trie va chen: flight, flow, flower\n";
    cout << "LCP cua tap hien tai: '" << get_longest_ancestor() << "' (Expected: fl)\n\n";

    cout << "=== 5. TEST ERASE ===\n";
    cout << "Erase 'flower': " << (erase_("flower") ? "Thanh cong" : "That bai") << '\n';
    cout << "Search 'flower': " << (search("flower") ? "YES" : "NO") << " (Expected: NO)\n";
    cout << "So tu co tien to 'flow': " << count_prefix("flow") << " (Expected: 1)\n";
    cout << "LCP sau khi xoa 'flower' (con 'flight' va 'flow'): '" << get_longest_ancestor() << "' (Expected: fl)\n";

    cout << "Erase 'flight': " << (erase_("flight") ? "Thanh cong" : "That bai") << '\n';
    cout << "LCP sau khi xoa 'flight' (chi con 'flow'): '" << get_longest_ancestor() << "' (Expected: flow)\n";
    TIME;
}