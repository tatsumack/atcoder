
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N), b(N);
    REP(i, N) {
        cin >> a[i];
    }
    REP(i, N) {
        cin >> b[i];
    }

    vector<pair<int, int>> d(N);
    REP(i, N) {
        d[i] = {abs(a[i] - b[i]), i};
    }

    int ans = 0;
    map<int, int> kind;
    REP(i, N) {
        int t = max(a[i], b[i]);
        ans += t;
        kind[t]++;
    }

    if (kind.size() >= K) {
        cout << ans << endl;
        return 0;
    }

    sort(d.begin(), d.end());
    REP(i, N) {
        auto kv = d[i];
        int tx = max(a[kv.second], b[kv.second]);
        int tn = min(a[kv.second], b[kv.second]);

        if (kind[tx] == 1) continue;
        if (kind[tn] > 0) continue;

        ans -= kv.first;
        kind[tn]++;
        kind[tx]--;

        if (kind.size() >= K) break;
    }
    cout << ans << endl;

    return 0;
}
