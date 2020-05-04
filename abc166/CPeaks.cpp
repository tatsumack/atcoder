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

class CPeaks {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> H(N);
        REP(i, N) cin >> H[i];

        vector<bool> good(N, true);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (H[a] >= H[b]) {
                good[b] = false;
            }
            if (H[a] <= H[b]) {
                good[a] = false;
            }
        }

        int res = 0;
        REP(i, N) {
            if (good[i]) res++;
        }
        cout << res << endl;
    }
};
