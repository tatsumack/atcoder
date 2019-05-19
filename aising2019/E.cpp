
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

int dp[5005][5005][2];
int sdp[5005][2];
vector<int> G[5005];
int A[5005];
int num[5005];

void dfs(int x, int par) {
    REP(j, G[x].size()) {
        int c = G[x][j];
        if (c == par) continue;
        dfs(c, x);
    }

    REP(i, 5005) sdp[i][0] = sdp[i][1] = INF;

    dp[x][0][A[x] < 0] = A[x];

    int sum = 1;
    REP(j, G[x].size()) {
        int c = G[x][j];
        if (c == par) continue;
        REP(s1, sum) {
            REP(s2, num[c]) {
                REP(k1, 2) {
                    REP(k2, 2) {
                        // つなぐ
                        if (dp[c][s2][k2] < INF) {
                            sdp[s1 + s2][k1 | k2] = min(sdp[s1 + s2][k1 | k2], dp[x][s1][k1] + dp[c][s2][k2]);
                        }

                        // 切る
                        if (dp[c][s2][k2] < 0 || (k2 == 0 && dp[c][s2][k2] < INF)) {
                            sdp[s1 + s2 + 1][k1] = min(sdp[s1 + s2 + 1][k1], dp[x][s1][k1]);
                        }
                    }
                }
            }
        }
        sum += num[c];
        REP(nj, sum) {
            REP(k, 2) {
                dp[x][nj][k] = sdp[nj][k];
                sdp[nj][k] = INF;
            }
        }

    }

    num[x] = sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    REP(i, N) REP(j, N - 1) REP(k, 2) dp[i][j][k] = INF;

    dfs(0, -1);

    int res = INF;
    REP(j, N) {
        if (dp[0][j][0] < INF) res = min(res, j);
        if (dp[0][j][1] < 0) res = min(res, j);
    }
    cout << res << endl;

    return 0;
}
