void xuli(str&   s) noexcept(false) {
    ll idx = -1;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            idx = i; break;
        }
    }
    if (idx == -1 || s.empty()) s = "0";
    else s.erase(0, idx);
}
str chiahaichuoi(str a, ll b) {
    str res = "0";
    ll idx = 0;
    for (cr c : a) {
        idx = idx * 10 + (c - '0');
        res += cr(idx / b + '0');
        idx %= b;
    }
    xuli(res);
    return res;
}