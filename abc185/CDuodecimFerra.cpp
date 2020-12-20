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

typedef pair<int, int> P;

class CDuodecimFerra {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int L;
        cin >> L;
        int a = 1;
        vector<bool> ok(12);
        REP(i, 11) {
            a *= (L - 1);
            FOR(j, 1, 11) {
                if (!ok[j] && a % j == 0) {
                    a /= j;
                    ok[j] = true;
                }
            }
            L--;
        }
        int b = 1;
        FOR(i, 1, 11) {
            if (ok[i]) continue;
            b *= i;
        }
        cout << a / b << endl;
    }
};
