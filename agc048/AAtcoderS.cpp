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

class AAtcoderS {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            string s;
            cin >> s;
            if (s > "atcoder") {
                cout << 0 << endl;
                continue;
            }
            bool ok = false;
            REP(i, s.size()) {
                if (s[i] != 'a') {
                    if (i > 1 && s[i] > 't') {
                        cout << i - 1 << endl;
                    } else {
                        cout << i << endl;
                    }
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                continue;
            }
        }

    }
};
