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

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return -INF;
}

class DFlatSubsequence {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        atcoder::segtree<int, op, e> seg(300005);
        REP(i, N) {
            int l = max(A[i] - K, 0LL);
            int r = min(A[i] + K, 300000LL);
            int val = max(seg.prod(l, r + 1), 0LL) + 1;
            seg.set(A[i], val);
        }

        int res = 0;
        FOR(i, 0, 300000) {
            res = max(res, seg.get(i));
        }
        cout << res << endl;
    }
};
