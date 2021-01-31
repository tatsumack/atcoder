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

class BAlcoholic {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, X;
        cin >> N >> X;
        vector<int> V(N), P(N);
        REP(i, N) {
            cin >> V[i] >> P[i];
        }
        X *= 100;
        int cur = 0;
        int sum = 0;
        for (; cur < N; cur++) {
            sum += V[cur] * P[cur];
            if (sum > X) {
                break;
            }
        }
        if (cur == N) {
            cout << -1 << endl;
            return;
        }
        cout << cur + 1 << endl;
    }
};
