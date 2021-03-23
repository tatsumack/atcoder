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

class DHanjo {
public:
    int H, W;

    int dfs(int pos, int bit, int A, int B) {
        if (bit >> pos & 1) return dfs(pos + 1, bit, A, B);
        if (pos == H * W) {
            return 1;
        }
        int res = 0;
        bit |= 1 << pos;
        if (A > 0) {
            if (pos % W < W - 1 && (bit >> (pos + 1) & 1) == 0) {
                res += dfs(pos + 1, bit | (1 << (pos + 1)), A - 1, B);
            }
            if (pos + W < H * W && (bit >> (pos + W) & 1) == 0) {
                res += dfs(pos + 1, bit | (1 << (pos + W)), A - 1, B);
            }
        }
        if (B > 0) {
            res += dfs(pos + 1, bit, A, B - 1);
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int A, B;
        cin >> H >> W >> A >> B;
        cout << dfs(0, 0, A, B) << endl;
    }
};
