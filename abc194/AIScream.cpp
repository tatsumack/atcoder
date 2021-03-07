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

class AIScream {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B;
        cin >> A >> B;
        int C = A + B;
        int res = 4;
        if (C >= 15 && B >= 8) {
            res = 1;
        } else if (C >= 10 && B >= 3) {
            res = 2;
        } else if (C >= 3) {
            res = 3;
        }
        cout << res << endl;
    }
};
