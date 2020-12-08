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

class FProgrammingContest {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, T;
        cin >> N >> T;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        if (N == 1) {
            cout << (A[0] <= T ? A[0] : 0) << endl;
            return;
        }

        set<int> first, second;
        int half = (N + 1) / 2;
        REP(i, 1LL << half) {
            int sum = 0;
            REP(j, half) {
                if ((i >> j & 1) == 0) continue;
                sum += A[j];
            }
            first.insert(sum);
        }
        REP(i, 1LL << (N - half)) {
            int sum = 0;
            REP(j, (N - half)) {
                if ((i >> j & 1) == 0) continue;
                sum += A[half + j];
            }
            second.insert(sum);
        }

        int res = 0;
        for (auto f : first) {
            auto itr = second.upper_bound(T - f);
            if (itr == second.begin()) continue;
            itr--;
            res = max(res, f + *itr);
        }
        cout << res << endl;
    }
};
