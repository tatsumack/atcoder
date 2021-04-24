#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;
typedef atcoder::modint1000000007 mint;

class DSquares {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;

        while (T--) {
            int N, A, B;
            cin >> N >> A >> B;

            mint x4 = N - A - B >= 0 ? mint(N - A - B + 2) * mint(N - A - B + 1) / 2 : 0;
            mint x3 = x4 * 2;
            mint x2 = (N - A + 1) * (N - B + 1) - x3;
            mint x1 = x2 * x2;
            mint res = mint(N - A + 1) * mint(N - A + 1) * mint(N - B + 1) * mint(N - B + 1) - x1;
            cout << res.val() << endl;
        }
    }
};
