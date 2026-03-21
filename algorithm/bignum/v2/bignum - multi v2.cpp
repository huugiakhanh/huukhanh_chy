void standardization(string& tmp) noexcept(true) {
    int idx = 0, ns = tmp.size();
    while (idx < ns - 1 && tmp[idx] == '0') idx++;
    tmp.erase(0, idx);
}
string multiplication(string& a, string& b) {
    bool ca = (a[0] == '-'), cb = (b[0] == '-');
    string ua, ub;
    if (ca == true) ua = a.substr(1, a.size() - 1);
    else ua = a;
    if (cb == true) ub = b.substr(1, b.size() - 1);
    else ub = b;
    if (ua == "0" || ub == "0") return "0";
    int na = ua.size(), nb = ub.size(), stk = 0, nho = 0;
    string res(na + nb, '0');
    for (int i = na - 1; i >= 0; i--) {
        nho = 0;
        for (int j = nb - 1; j >= 0; j--) {
            stk = (res[i + j + 1] - '0') + (ua[i] - '0') * (ub[j] - '0') + nho;
            res[i + j + 1] = char((stk % 10) + '0'); nho = stk / 10;
        }
        res[i] += nho;
    }
    standardization(res);
    if (cb != ca && res != "0") res = '-' + res;
    return res;
}