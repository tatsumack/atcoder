
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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;


// 分割数
int part[1005][1005];
int mod = 1e9 + 7;

// nをm個に分割
// part[i][j]: jをi個に分割
int precalc(int n, int m) {
    part[0][0] = 1;
    FOR(i, 1, m) {
        FOR(j, 0, n) {
            if (j - i >= 0) {
                part[i][j] = (part[i - 1][j] + part[i][j - i]) % mod;
            } else {
                part[i][j] = part[i - 1][j];
            }
        }
    }
}

int solve(vector<int> kill, int death) {
    vector<pair<int, int>> cnt;
    cnt.push_back({kill[0], 1});
    FOR(i, 1, kill.size() - 1) {
        if (cnt.back().first == kill[i]) {
            cnt.back().second++;
        } else {
            cnt.push_back({kill[i], 1});
        }
    }

    vector<vector<int>> dp(cnt.size() + 1, vector<int>(death + 1, 0));

    dp[0][0] = 1;
    REP(i, cnt.size()) {
        FOR(j, 0, death) {
            FOR(k, 0, death - j) {
                dp[i + 1][j + k] += dp[i][j] * part[cnt[i].second][k];
                dp[i + 1][j + k] %= mod;
            }
        }
    }

    return dp[cnt.size()][death];

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> killA(N);
    vector<int> killB(M);

    int deathA = 0;
    int deathB = 0;
    REP(i, N) cin >> killA[i], deathB += killA[i];
    REP(i, M) cin >> killB[i], deathA += killB[i];

    precalc(1001, 1001);

    cout << (solve(killA, deathA) * solve(killB, deathB)) % mod << endl;

    return 0;
}
