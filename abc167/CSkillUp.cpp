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

class CSkillUp {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, X;
        cin >> N >> M >> X;
        vector<int> C(N);
        vector<vector<int>> A(N, vector<int>(M));
        REP(i, N) {
            cin >> C[i];
            REP(j, M) {
                cin >> A[i][j];
            }
        }

        int res = INF;
        REP(s, 1 << N) {
            vector<int> x(M);
            int cost = 0;
            REP(i, N) {
                if (s >> i & 1) {
                    REP(j, M) {
                        x[j] += A[i][j];
                    }
                    cost += C[i];
                }
            }
            bool ok = true;
            REP(j, M) {
                if (x[j] < X) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            res = min(res, cost);
        }
        if (res >= INF) res = -1;
        cout << res << endl;
    }
};
