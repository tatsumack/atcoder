
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

    int N;
    cin >> N;

    map<int, int> m;
    vector<int> v(N);
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        v[i] = a;
        m[a] = b;
    }
    sort(v.begin(), v.end());

    int M;
    cin >> M;

    REP(i, M) {
        int t;
        cin >> t;
        int l = lower_bound(v.begin(), v.end(), t) - v.begin();

        if (l >= N) l = N-1;

        int ans = m[v[l]] + max(0LL, (t - v[l]));
        if (l > 0) ans = min(ans, m[v[l - 1]] + max(0LL, (t - v[l - 1])));
        cout << ans << endl;
    }

    return 0;
}
