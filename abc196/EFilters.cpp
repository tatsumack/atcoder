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

class EFilters {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N), t(N);
        REP(i, N) cin >> a[i] >> t[i];

        int Q;
        cin >> Q;
        vector<int> X(Q);
        REP(i, Q) {
            cin >> X[i];
        }

        int low = -INF;
        int high = INF;
        int sum = 0;
        REP(i, N) {
            if (t[i] == 1) {
                low += a[i];
                high += a[i];
                sum += a[i];
            }
            if (t[i] == 2) {
                low = max(low, a[i]);
                high = max(high, a[i]);
            }
            if (t[i] == 3) {
                low = min(low, a[i]);
                high = min(high, a[i]);
            }
        }

        REP(i, Q) {
            cout << clamp(X[i] + sum, low, high) << endl;
        }
    }
};
