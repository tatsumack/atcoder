#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class BPalindromeWithLeadingZeros {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        string tmp;
        bool ok = false;
        REP(i, s.size()) {
            if (s[i] != '0') {
                ok = true;
            }
            if (s[i] == '0' && !ok) continue;
            if (ok) {
                tmp += s[i];
            }
        }
        int l = 0;
        int r = tmp.size() - 1;
        while (l < r) {
            if (tmp[l] != tmp[r]) {
                cout << "No" << endl;
                return;
            }
            l++, r--;
        }
        cout << "Yes" << endl;
    }
};
