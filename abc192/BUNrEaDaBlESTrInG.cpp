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

class BUNrEaDaBlESTrInG {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        bool ok = true;
        REP(i, s.size()) {
            char c = s[i];
            if (i % 2) {
                if (!('A' <= c && c <= 'Z')) {
                    ok = false;
                }
            } else {
                if (!('a' <= c && c <= 'z')) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
};
