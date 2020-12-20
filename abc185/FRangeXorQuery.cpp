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

typedef pair<int, int> P;

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class FRangeXorQuery {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;
        vector<int> A(N);

        vector<BIT> v(30, BIT(N + 1));

        REP(i, N) {
            cin >> A[i];
            REP(j, 30) {
                if (A[i] >> j & 1) {
                    v[j].add(i + 1, 1);
                }
            }
        }
        REP(i, Q) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 1) {
                REP(j, 30) {
                    if (y >> j & 1) {
                        v[j].add(x, 1);
                    }
                }
            } else {
                int res = 0;
                REP(j, 30) {
                    int val = v[j].sum(y) - v[j].sum(x - 1);
                    if (val % 2 == 1) {
                        res += (1LL << j);
                    }
                }
                cout << res << endl;
            }
        }
        return;
    }
};
