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

typedef atcoder::modint998244353 mint;
using namespace std;

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

class DIWannaWinTheGame {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<mint> dp(N + 1);
        dp[0] = 1;
        combination cb(N + 1);
        while (M > 0) {
            vector<mint> next(N + 1);
            for (int i = 0; i <= N; i++) {
                if (dp[i].val() == 0) continue;
                for (int j = 0; j <= N; j += 2) {
                    int ni = i + j;
                    if ((ni & 1) != (M & 1)) continue;
                    next[ni >> 1] += dp[i] * cb(N, j);
                }
            }
            swap(next, dp);
            M >>= 1;
        }
        cout << dp[0].val() << endl;
    }
};
