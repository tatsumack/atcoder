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

int dp[70000000];
int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, pair<int, int> > used;
    vector<pair<int, int> > empty;
    REP(i, 5) REP(j, 5) {
        int a;
        cin >> a;
        if (a > 0) {
            used[a] = {i, j};
        } else {
            empty.push_back({i, j});
        }
    }

    dp[0] = 1;
    REP(s, 1 << 25) {
        if (dp[s] == 0) continue;
        int cnt = 1;
        REP(i, 25) if (s & (1 << i)) cnt++;
        if (used.count(cnt) > 0) {
            auto p = used[cnt];
            int cs = 1 << (p.first * 5 + p.second);
            if (s & cs) continue;
            if (p.first > 0 && p.first < 4) {
                int ts1 = (p.first - 1) * 5 + p.second;
                int ts2 = (p.first + 1) * 5 + p.second;
                if (((s >> ts1) ^ (s >> ts2)) & 1) continue;
            }
            if (p.second > 0 && p.second < 4) {
                int ts1 = p.first * 5 + p.second - 1;
                int ts2 = p.first * 5 + p.second + 1;
                if (((s >> ts1) ^ (s >> ts2)) & 1) continue;
            }
            dp[s | (1 << (p.first * 5 + p.second))] =
                (dp[s | (1 << (p.first * 5 + p.second))] + dp[s]) % mod;
        } else {
            REP(i, empty.size()) {
                auto p = empty[i];
                int cs = 1 << (p.first * 5 + p.second);
                if (s & cs) continue;
                if (p.first > 0 && p.first < 4) {
                    int ts1 = (p.first - 1) * 5 + p.second;
                    int ts2 = (p.first + 1) * 5 + p.second;
                    if (((s >> ts1) ^ (s >> ts2)) & 1) continue;
                }
                if (p.second > 0 && p.second < 4) {
                    int ts1 = p.first * 5 + p.second - 1;
                    int ts2 = p.first * 5 + p.second + 1;
                    if (((s >> ts1) ^ (s >> ts2)) & 1) continue;
                }
                dp[s | (1 << (p.first * 5 + p.second))] =
                    (dp[s | (1 << (p.first * 5 + p.second))] + dp[s]) % mod;
            }
        }
    }
    cout << dp[(1 << 25) - 1] << endl;
    return 0;
}
