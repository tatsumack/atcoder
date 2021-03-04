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

class BABC {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, C;
        cin >> A >> B >> C;
        int b = B % 4;
        if (C % 2 == 0) {
            b = (b * b) % 4;
        }
        if (C % 2 == 1 && C != 1 && b == 2) {
            b = 0;
        }
        if (b == 0) b = 4;
        int res = 1;
        REP(i, b) {
            res *= (A % 10);
            res %= 10;
        }
        cout << res << endl;
    }
};
