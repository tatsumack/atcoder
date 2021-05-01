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

class B {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        double N, D, H;
        cin >> N >> D >> H;

        double res = 0;
        REP(i, N) {
            double d, h;
            cin >> d >> h;
            double x = d * (H-h) / (D - d);
            res = max(res, h - x);
        }
        fcout << res << endl;
    }
};
