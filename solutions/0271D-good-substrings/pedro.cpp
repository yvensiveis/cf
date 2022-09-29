#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int M = 1e9 + 9;
const int P = 31;

int fexp(int b, int e) {
    if (e == 0) return 1;
    int f = fexp(b, e >> 1);
    f = ((ll) f * f) % M;
    if (e & 1) f = ((ll) f * b) % M;
    return f;
}

void solve() {
    string a; cin >> a;
    int n = a.size();
    string g; cin >> g;
    int k; cin >> k;

    vector<bool> b(n);
    vector<int> ord(n);
    for (int i = 0; i < n; ++i) {
        b[i] = g[a[i] - 'a'] == '0';
        ord[i] = a[i] - 'a' + 1;
    }

    int ans = 0;

    for (int len = 1; len <= n; ++len) {
        int ck = 0;
        set<int> c;

        int hsh = 0, p = 1;
        for (int i = 0; i < n; ++i) {
            ck += b[i];
            if (i >= len) {
                ck -= b[i - len];
                hsh = (hsh - ord[i - len] + M) % M;
                hsh = ((ll) hsh * fexp(P, M - 2)) % M;
                hsh = (hsh + (ll) ord[i] * p) % M;
            } else {
                hsh = (hsh + (ll) ord[i] * p) % M;
                if (i + 1 < len)
                    p = ((ll) p * P) % M;
            }

            if (i >= len - 1) {
                if (ck <= k) {
                    c.insert(hsh);
                }
            }
        }
        ans += c.size();
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
