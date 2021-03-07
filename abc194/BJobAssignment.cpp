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

class BJobAssignment {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int res = INF;
        vector<int> A(N), B(N);
        REP(i, N) {
            cin >> A[i] >> B[i];
            res = min(res, A[i] + B[i]);
        }
        REP(i, N) {
            REP(j, N) {
                if (i == j) continue;
                res = min(res, max(A[i], B[j]));
            }
        }
        cout << res << endl;
    }
};
