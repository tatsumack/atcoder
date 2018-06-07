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
#define INF (3e15)

using namespace std;

int dw[4] = {-1, 0, 0, 1};
int dh[4] = {0, -1, 1, 0};
int H, W, A[1005][1005], dp[1005][1005];

int dfs(int h, int w)
{
    if (dp[h][w] != 0)
        return dp[h][w];

    int res = 0;
    bool isStop = true;
    REP(i, 4)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh < 0 || nw < 0 || nw >= W || nh >= H)
            continue;
        if (A[nh][nw] <= A[h][w])
            continue;
        isStop = false;

        res += dfs(nh, nw) + 1;
    }
    if (isStop)
        return dp[h][w] = 1;

    return dp[h][w] = res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    REP(i, H)
    {
        REP(j, W)
        cin >> A[i][j];
    }

    int ans = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            ans += dfs(i, j);
        }
    }

    REP(i, H)
    {
        REP(j, W)
        {
            DUMP(i)
            DUMP(j)
            DUMP(dp[i][j])
        }
    }

    cout << ans << endl;

    return 0;
}
