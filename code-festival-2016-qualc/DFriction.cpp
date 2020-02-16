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

class DFriction {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> G(H, vector<char>(W, 0));
        REP(i, H) {
            REP(j, W) {
                cin >> G[i][j];
            }
        }

        int res = 0;
        REP(i, W - 1) {
            vector<vector<int>> cost(H + 1, vector<int>(H + 1));
            vector<vector<int>> h(H + 1, vector<int>(H + 1));
            REP(j, H + 1) REP(k, H + 1) cost[j][k] = INF, h[j][k] = INF;
            cost[0][0] = 0;
            REP(j, H + 1) h[j][0] = 0, h[0][j] = 0;
            h[0][0] = 0;
            REP(j, H) REP(k, H) h[j + 1][k + 1] = min(h[j + 1][k + 1], h[j][k] + (G[j][i] == G[k][i + 1]));

            REP(j, H + 1) {
                REP(k, H + 1) {
                    if (j + 1 <= H) cost[j + 1][k] = min(cost[j + 1][k], cost[j][k] + h[H - j][H - k]);
                    if (k + 1 <= H) cost[j][k + 1] = min(cost[j][k + 1], cost[j][k] + h[H - j][H - k]);
                }
            }
            res += cost[H][H];
        }
        cout << res << endl;
    }
};
