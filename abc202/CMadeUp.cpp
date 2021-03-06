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

class CMadeUp {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N), C(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];
        REP(i, N) {
            cin >> C[i];
            C[i]--;
        }

        map<int, int> cnt;
        REP(i, N) {
            cnt[A[i]]++;
        }

        int res = 0;
        REP(i, N) {
            res += cnt[B[C[i]]];
        }
        cout << res << endl;
    }
};
