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

class BRowToColumn {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<vector<char>> a(N, vector<char>(N, 0));
        REP(i, N) REP(j, N) cin >> a[i][j];

        set<int> cols, exists;
        vector<int> rows(N);
        bool ok = false;
        REP(i, N) {
            REP(j, N) {
                char c = a[i][j];
                if (c == '.') {
                    rows[i]++;
                    cols.insert(j);
                } else {
                    ok = true;
                    exists.insert(j);
                }
            }
        }

        if (!ok) {
            cout << -1 << endl;
            return;
        }

        int res = INF;
        REP(i, N) {
            int tmp;
            if (exists.count(i)) {
                tmp = rows[i];
            } else {
                tmp = rows[i] + 1;
            }
            res = min(tmp, res);
        }
        cout << res + cols.size() << endl;
    }
};
