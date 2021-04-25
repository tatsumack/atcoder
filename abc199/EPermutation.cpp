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

class EPermutation {
public:
    int bitcount(int n) {
        int cnt = 0;
        REP(i, 20) {
            if (n >> i & 1) cnt++;
        }
        return cnt;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> dp(1LL << N);
        vector<vector<tuple<int, int>>> v(20);
        REP(i, M) {
            int x, y, z;
            cin >> x >> y >> z;
            y--;
            v[x].emplace_back(y, z);
        }
        dp[0] = 1;
        REP(i, 1 << N) {
            int num = bitcount(i);
            REP(j, N) {
                if (i >> j & 1) continue;
                bool ok = true;
                for (auto p : v[num + 1]) {
                    int n = 0;
                    int y, z;
                    tie(y, z) = p;
                    if (j <= y) n++;
                    REP(k, N) {
                        if (i >> k & 1) {
                            if (k <= y) n++;
                        }
                    }
                    if (n > z) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                dp[i | 1 << j] += dp[i];
            }
        }
        cout << dp[(1 << N) - 1] << endl;
    }
};
