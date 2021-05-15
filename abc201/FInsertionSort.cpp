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

class FInsertionSort {
public:
    template<class T>
    vector<T> LIS(vector<T> a, bool is_strong = true) {
        int n = (int) a.size();
        vector<T> dp(n, INF);
        for (int i = 0; i < n; ++i) {
            if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
            else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
        return dp;
        //return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> P(N), A(N), B(N), C(N);
        REP(i, N) cin >> P[i];
        REP(i, N) cin >> A[i] >> B[i] >> C[i];

        auto dp = LIS(P);
        int ridx = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
        int r = dp[ridx - 1];
        int l = r - ridx + 1;

        int res = 0;
        REP(i, N) {
            int p = P[i]-1;
            if (P[i] < l) {
                res += min(A[p], B[p]);
            }
            if (P[i] > r) {
                res += min(A[p], C[p]);
            }
        }
        cout << res << endl;
    }
};
