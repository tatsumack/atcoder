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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, M, P, Q, R;

vector<pair<int, int> > v[30];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> P >> Q >> R;
    REP(i, R) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        v[x].push_back({y, z});
    }

    int ans = 0;
    REP(i, 1 << N) {
        int b = 0;
        REP(j, N) if (i & 1 << j) b++;
        if (b != P) continue;

        vector<int> vy(M + 1, 0);
        REP(j, N) {
            if ((i & 1 << j) == 0) continue;
            REP(k, v[j].size()) {
                int to = v[j][k].first;
                int cost = v[j][k].second;
                vy[to] += cost;
            }
        }
        sort(vy.begin(), vy.end(), greater<int>());

        int tmp = 0;
        REP(j, Q) tmp += vy[j];
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}