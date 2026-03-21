void chuanhoa(string& tmp) noexcept(true) {
    int idx = 0, ns = tmp.size();
    while (idx < ns - 1 && tmp[idx] == '0') idx++;
    tmp.erase(0, idx);
}
int cmp(string& a, string& b) {
    if (a.size() != b.size()) {
        if (a.size() < b.size()) return -1;
        return 1;
    } if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
string negative(string& a, string& b) {
    if (b.size() > a.size()) swap(a, b);
    int na = a.size(), nb = b.size(), stk, nho = 0;
    b = string(na - nb, '0') + b;
    string res(na, '0');
    for (int i = na - 1; i >= 0; --i) {
        stk = (a[i] - '0') - (b[i] - '0') - nho;
        if (stk < 0) stk += 10, nho = 1;
        else nho = 0;
        res[i] = char(stk + '0');
    }
    // reverse(res.begin(), res.end());
    chuanhoa(res);
    return res;
}
string total(string& a, string& b) {
    bool ca = (a[0] == '-'), cb = (b[0] == '-');
    string ua, ub, res = "";
    if (ca == true) ua = a.substr(1, a.size() - 1);
    else ua = a;
    if (cb == true) ub = b.substr(1, b.size() - 1);
    else ub = b;
    if (ca == cb) {
        if (ub.size() > ua.size()) swap(ua, ub);
        int na = ua.size(), nb = ub.size(), stk, nho = 0;
        ub = string(na - nb, '0') + ub;
        res.resize(na, '0');
        for (int i = na - 1; i >= 0; --i) {
            stk = (ua[i] - '0') + (ub[i] - '0') + nho;
            res[i] = char((stk % 10) + '0'); nho = stk / 10;
        }
        res = char(nho + '0') + res;
        chuanhoa(res);
        if (ca == true && res != "0") res = '-' + res;
        if (res == "") res = "0";
        return res;
    }
    int anhnguyet = cmp(ua, ub);
    if (anhnguyet == 0) return "0";
    if (anhnguyet == 1) {
        res = negative(ua, ub);
        if (ca == true && res != "0") res = '-' + res;
    }
    if (anhnguyet == -1) {
        res = negative(ub, ua);
        if (cb == true && res != "0") res = '-' + res;
    }
    if (res == "") res = "0";
    return res;
}
string subtract(string& a, string& b) {
    string nb;
    if (b[0] == '-') nb = b.substr(1, b.size() - 1);
    else nb = '-' + b;
    if (nb == "-0") nb = "0";
    return total(a, nb);
}