void xuli(str& s) noexcept(true) {
    ll idx = -1;
    for (ll i = 0; i < s.size(); ++i) {
        if (s[i] != '0') {
            idx = i; break;
        }
    }
    if (idx == -1 || s.empty()) s = "0";
    else s.erase(0, idx);
}
str truhaichuoi(str a, str b) {
    bl check = true;
    if (b.size() > a.size()) swap(a, b), check = false;
    ll an = a.size(), bn = b.size();
    b = string(an - bn, '0') + b;
    vll res(an + 1); ll nho = 0;
    for (ll i = an - 1; i >= 0; --i) {
        ll x = a[i] - '0', y = b[i] - '0';
        ll tong = x - y + nho;
        res[i + 1] = tong % 10;
        nho = tong / 10;
    }
    res[0] = nho;
    str ress = "";
    for (ll i = 0; i <= an; ++i) ress += cr(res[i] + '0');
    xuli(ress);
    if (check == false) ress = '-' + ress;
    return ress;
}