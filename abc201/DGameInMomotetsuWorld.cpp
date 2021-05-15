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

int dx[2] = {1, 0};
int dy[2] = {0, 1};

class DGameInMomotetsuWorld {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> A(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> A[i][j];
        vector<vector<int>> dp(H, vector<int>(W));
        for (int i = H - 1; i >= 0; i--) {
            for (int j = W - 1; j >= 0; j--) {
                if (i == H - 1 && j == W - 1) continue;
                int isT = (i + j) % 2 == 0;
                dp[i][j] = isT ? -INF : INF;
                REP(k, 2) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= H || ny >= W) continue;
                    int next = (A[nx][ny] == '+') ? 1 : -1;
                    if (!isT) next *= -1;
                    dp[i][j] = isT ? max(dp[i][j], dp[nx][ny] + next) : min(dp[i][j], dp[nx][ny] + next);
                }
            }
        }
        if (dp[0][0] > 0) {
            cout << "Takahashi" << endl;
        } else if (dp[0][0] < 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Draw" << endl;
        }

    }
};
