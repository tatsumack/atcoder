#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef atcoder::modint1000000007 mint;

class ELamps {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<string> S(H);
        REP(i, H) {
            cin >> S[i];
        }
        vector<vector<int>> L(H, vector<int>(W));
        vector<vector<int>> R(H, vector<int>(W));
        vector<vector<int>> U(H, vector<int>(W));
        vector<vector<int>> D(H, vector<int>(W));
        REP(i, H) {
            FOR(j, 1, W - 1) {
                if (S[i][j - 1] == '.') {
                    L[i][j] = L[i][j - 1] + 1;
                } else {
                    L[i][j] = 0;
                }
            }
            REV(j, W - 2, 0) {
                if (S[i][j + 1] == '.') {
                    R[i][j] = R[i][j + 1] + 1;
                } else {
                    R[i][j] = 0;
                }
            }
        }
        REP(j, W) {
            FOR(i, 1, H - 1) {
                if (S[i - 1][j] == '.') {
                    U[i][j] = U[i - 1][j] + 1;
                } else {
                    U[i][j] = 0;
                }
            }
            REV(i, H - 2, 0) {
                if (S[i + 1][j] == '.') {
                    D[i][j] = D[i + 1][j] + 1;
                } else {
                    D[i][j] = 0;
                }
            }
        }
        vector<mint> two(H * W + 1);
        two[0] = 1;
        REP(i, H * W) two[i + 1] = two[i] * 2;

        int sum = 0;
        REP(i, H) REP(j, W) if (S[i][j] == '.') sum++;

        mint res = 0;
        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '#') continue;
                int val = L[i][j] + R[i][j] + U[i][j] + D[i][j] + 1;
                res += (two[val] - 1) * (two[sum - val]);
            }
        }
        cout << res.val() << endl;
    }
};
