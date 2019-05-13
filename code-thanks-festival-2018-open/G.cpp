
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


template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

int N, K;


vector<vector<int>> memo;
int dfs(const vector<vector<int>>& dp, int cur, int kind) {
    if (cur == dp.size()) return kind >= K ? 0 : -INF;
    if (memo[cur][kind] != -1) {
        return memo[cur][kind];
    }

    int res = -INF;
    REP(j, dp[cur].size()) {
        if (dp[cur][j] == 0) continue;
        res = max(res, dp[cur][j] + dfs(dp, cur + 1, kind + j));
    }

    return memo[cur][kind] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    vector<int> a(N), b(N), p(N + 1);
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N) {
        cin >> b[i];
        p[a[i]] = b[i];
    }

    vector<bool> used(N);

    int m = 0;
    vector<vector<int>> cycles;
    FOR(i, 1, N) {
        if (used[i]) continue;

        int v = i;
        cycles.push_back({});
        while (!used[v]) {
            cycles.back().push_back(v);
            used[v] = true;
            v = p[v];
        }
    }

    vector<vector<int>> dp2(cycles.size());
    REP(t, cycles.size()) {
        auto cycle = cycles[t];
        int sz = cycle.size();
        dp2[t].resize(sz + 1);
        if (sz == 1) {
            dp2[t][1] = cycle[0];
            continue;
        }

        int pre = 0, cur = 1;
        auto dp = make_v<int>(2, sz + 1, 2, 2);
        dp[pre][1][0][1] = cycle[0];
        dp[pre][1][1][0] = cycle[1];
        FOR(i, 2, sz - 1) {
            FOR(j, (i + 1) / 2, i) {
                REP(l, 2) {
                    int tmp1 = max(dp[pre][j][1][l], dp[pre][j - 1][0][l]) + cycle[i - 1];
                    dp[cur][j][0][l] = max(dp[cur][j][0][l], tmp1);

                    int tmp2 = max(dp[pre][j - 1][1][l], dp[pre][j - 1][0][l]) + cycle[i];
                    dp[cur][j][1][l] = max(dp[cur][j][1][l], tmp2);
                }
            }
            swap(pre, cur);
        }

        FOR(j, (sz + 1) / 2, sz) {
            dp[cur][j][0][0] = max(dp[pre][j][1][0], dp[pre][j - 1][0][0]) + cycle[sz - 1];
            dp[cur][j][0][1] = max(dp[pre][j][1][1], dp[pre][j - 1][0][1]) + cycle[sz - 1];
            dp[cur][j][1][0] = max(dp[pre][j - 1][1][0], dp[pre][j][0][0]) + cycle[0];
            dp[cur][j][1][0] = max(dp[pre][j - 1][1][0], dp[pre][j][0][0]) + cycle[0];
        }

        FOR(j, (sz + 1) / 2, sz) {
            REP(k, 2) {
                REP(l, 2) {
                    dp2[t][j] = max(dp2[t][j], dp[cur][j][k][l]);
                }
            }
        }
    }

    memo.resize(dp2.size(), vector<int>(N + 1, -1));
    cout << dfs(dp2, 0, 0) << endl;

    return 0;
}
