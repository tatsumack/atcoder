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

class ALongCommonSubsequence {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int N;
            cin >> N;
            REP(i, 3) {
                string s;
                cin >> s;
            }
            string res;
            REP(i, N) res += '0';
            REP(i, N) res += '1';
            res += '0';
            cout << res << endl;
        }
    }
};
