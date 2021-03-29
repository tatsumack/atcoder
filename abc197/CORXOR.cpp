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

class CORXOR {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        int res = INF;
        REP(i, 1 << N) {
            int prev = 0;
            int val = 0;
            vector<int> v;
            REP(j, N) {
                int idx = i >> j & 1;
                if (idx != prev) {
                    v.push_back(val);
                    val = A[j];
                } else {
                    val |= A[j];
                }
                prev = idx;
            }
            v.push_back(val);

            int tmp = 0;
            for (auto n : v) tmp ^= n;
            res = min(res, tmp);
        }
        cout << res << endl;
    }
};
