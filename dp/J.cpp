
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

double dp[305][305][305];
int num[4];
int N;

double dfs(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] > 0) return dp[i][j][k];

    if (i + j + k == 0) return 0;

    double res = 0;
    res += dfs(i - 1, j, k) * i;
    res += dfs(i + 1, j - 1, k) * j;
    res += dfs(i, j + 1, k - 1) * k;
    res += N;
    res /= (i + j + k);

    return dp[i][j][k] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<int> a(N);
    REP(i, N) cin >> a[i];

    REP(i, N) {
        num[a[i]]++;
    }

    REP(i, num[1] + 1) REP(j, num[2] + 1) REP(k, num[3] + 1) dp[i][j][k] = -1;

    fcout << dfs(num[1], num[2], num[3]) << endl;

    return 0;
}
