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

class DTeleporter {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> next(65, vector<int>(N));
        REP(i, N) {
            int a;
            cin >> a;
            a--;
            next[0][i] = a;
        }
        REP(k, 61) {
            REP(i, N) {
                next[k+1][i] = next[k][next[k][i]];
            }
        }

        int cur = 0;
        REV(k, 60, 0) {
            if (K >> k & 1) {
                cur = next[k][cur];
            }
        }
        cout << cur + 1 << endl;
    }
};
