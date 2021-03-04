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

using mint = atcoder::modint998244353;
int mod = 998244353;

class DSkyReflector {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, K;
        cin >> N >> M >> K;

        mint res = 0;
        FOR(k, 1, K) {
            mint tmp = 1;
            tmp *= atcoder::pow_mod(k, N, mod) - atcoder::pow_mod(k - 1, N, mod);
            int b = K - k + 1;
            if (N == 1) {
                tmp *= atcoder::pow_mod(b, M, mod) - atcoder::pow_mod(b - 1, M, mod);
            } else if (M == 1) {
                tmp *= 1;
            } else {
                tmp *= atcoder::pow_mod(b, M, mod);
            }
            res += tmp;
        }
        cout << res.val() << endl;
    }
};
