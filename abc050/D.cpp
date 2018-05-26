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
typedef pair<int, int> P;

int N;
map<P, int> dp;

int mod = 1000000007;

int dfs(int s, int x) {
    if (dp.count({s, x}) != 0) {
        return dp[{s, x}];
    }
    if (s == 0 && x == 0) {
        return dp[{s, x}] = 1;
    }
    int res = dfs(s / 2, x / 2);

    if (s >= 1 && x >= 1) {
        res = (res + dfs((s - 1) / 2, (x - 1) / 2)) % mod;
    }

    if (s >= 2) {
        res = (res + dfs((s - 2) / 2, x / 2)) % mod;
    }
    return dp[{s, x}] = res % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cout << dfs(N, N) << endl;
    return 0;
}
