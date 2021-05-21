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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

class BJoker {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> P(N * N);
        REP(i, N * N) {
            cin >> P[i];
            P[i]--;
        }

        vector<vector<int>> dp(N, vector<int>(N));
        REP(i, N) {
            REP(j, N) {
                dp[i][j] = min({i, N - 1 - i, j, N - 1 - j});
            }
        }

        vector<vector<bool>> exists(N, vector<bool>(N, true));
        int res = 0;
        REP(i, N * N) {
            int x = P[i] / N;
            int y = P[i] % N;
            if (dp[x][y] > 0) {
                res += dp[x][y];
            }
            exists[x][y] = false;

            queue<tuple<int, int>> q;
            q.push({x, y});
            while (!q.empty()) {
                int cx, cy;
                tie(cx, cy) = q.front();
                q.pop();
                REP(k, 4) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    int nextCost = dp[cx][cy] + (exists[cx][cy] ? 1 : 0);
                    if (nextCost < dp[nx][ny]) {
                        dp[nx][ny] = nextCost;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << res << endl;
    }
};
