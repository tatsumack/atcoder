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

class CARCWrecker2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        REP(i, N) {
            if (i % 2 == 1) A[i] *= -1;
        }

        int cur = 0;
        map<int, int> m;
        int res = 0;
        m[0]++;
        REP(i, N) {
            cur += A[i];
            res += m[cur];
            m[cur]++;
        }
        cout << res << endl;
    }
};
