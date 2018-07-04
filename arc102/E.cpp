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

typedef pair<int, int> P;

int N, A[300000];
P f[300000];

P merge(P& l, P& r) {
    vector<int> v = {l.first, l.second, r.first, r.second};
    sort(v.begin(), v.end());
    return {v[3], v[2]};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, 1 << N) cin >> A[i];
    REP(i, 1 << N) f[i] = {A[i], 0};

    REP(i, N) REP(j, 1 << N) {
        if (j & 1 << i) {
            f[j] = merge(f[j], f[j ^ 1 << i]);
        }
    }

    int ans = 0;
    FOR(i, 1, (1 << N) - 1) {
        ans = max(ans, f[i].first + f[i].second);
        cout << ans << endl;
    }
    return 0;
}
