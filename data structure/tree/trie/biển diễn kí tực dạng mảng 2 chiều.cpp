const int MAXNODE = 1000000; // độ dài tối đa của chuỗi
int trie[MAXNODE][26]; // trie[u][c] = nút con theo ký tự c
bool ok[MAXNODE];     // nếu true là kết thúc tại node này còn false là không
int cnt[MAXNODE];     // số chuỗi đi qua / kết thúc tại nút
int node = 1;         // số nút hiện có (gốc = 0)

void input() noexcept(false) {
    memset(trie, 0, sizeof(trie)); // giá trị ban đàu bằng 0
    memset(cnt, 0, sizeof(cnt)); // gia trị ban đầu bằng 0
    TIME;
}
void insert(const string& s) {
    int u = 0; // gốc
    for (char ch : s) { // duyệt s
        int c = ch - 'a'; // lấy max ascii
        if (!trie[u][c]) trie[u][c] = node++; // tăng node
        u = trie[u][c]; //
        cnt[u]++;
    }
    ok[u] = true;
}
// vd các hàm
bool search(const string& s) {
    int u = 0; // gốc
    for (char ch : s) {
        int c = ch - 'a';
        if (!trie[u][c]) return false; // không có nhánh
        u = trie[u][c];
    }
    return ok[u] == true; // đã từng được chèn
}
int countPrefix(const string& s) {
    int u = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (!trie[u][c]) return 0;
        u = trie[u][c];
    }
    return cnt[u];
}
void output() noexcept(true) {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s; insert(s);
    }
    int m; cin >> m; // m truy vấn
    while (m--) {
        string k; cin >> k;
        cout << search(k) << '\n'; // kiểm tra k có là sâu tiền tố của cái xấu s ko
    }
    TIME;
}