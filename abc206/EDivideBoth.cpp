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

class EDivideBoth {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int L, R;
        cin >> L >> R;

        vector<int> cnt(R + 10), cnt2(R + 10);
        for (int g = R; g > 1; g--) {
            int val = R / g - (L - 1) / g;
            cnt[g] = val;
            cnt2[g] = val * val;
            int gg = g * 2;
            while (gg <= R) {
                cnt2[g] -= cnt2[gg];
                gg += g;
            }
        }
        int res = 0;
        FOR(g, 1, R) {
            res += cnt2[g];
            if (max(2LL, L) <= g && g <= R) {
                res -= 2 * cnt[g] - 1;
            }
        }
        cout << res << endl;
    }
};
