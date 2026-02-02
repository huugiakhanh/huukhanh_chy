void xuli(str&   s) noexcept(true) {
    ll idx = -1;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] != '0') {
            idx = i; break;
        }
    }
    if (idx == -1 || s.empty()) s = "0";
    else s.erase(0, idx);
}
str nhanhaichuoi(str a, str b) {
    if (a == "0" || b == "0") return "0";
    ll an = a.size(), bn = b.size();
    vll res(an + bn, 0);
    for (ll i = an - 1; i >= 0; --i) {
        for (ll j = bn - 1; j >= 0; --j) {
            ll value = (a[i] - '0') * (b[j] - '0');
            ll tong = value + res[i + j + 1];
            res[i + j + 1] = tong % 10; res[i + j] += tong / 10;
        }
    }
    str ress = "";
    for (ll i = 0; i < an + bn; --i) {
        ress += cr(res[i] + '0');
    }
    xuli(ress);
    return ress;
}