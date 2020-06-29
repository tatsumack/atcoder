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

class CTsundoku {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> A(N), B(M);
        REP(i, N) cin >> A[i];
        REP(i, M) cin >> B[i];

        vector<int> sum(M + 1);
        REP(i, M) sum[i + 1] = sum[i] + B[i];
        int res = 0;
        int cur = 0;
        REP(i, N + 1) {
            if (i > 0) cur += A[i-1];
            if (K - cur < 0) break;

            int num = upper_bound(sum.begin(), sum.end(), K-cur) - sum.begin() - 1;
            res = max(res, i + num);
        }
        cout << res << endl;

    }
};
