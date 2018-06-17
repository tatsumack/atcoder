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

int N, M;

int x[1005], y[1005], z[1005];

struct Sign {
    int x, y, z;
};
Sign s[8] = {Sign{1, 1, 1},   Sign{-1, 1, 1},  Sign{1, -1, 1},
             Sign{1, 1, -1},  Sign{-1, -1, 1}, Sign{1, -1, -1},
             Sign{-1, 1, -1}, Sign{-1, -1, -1}};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    REP(i, N) { cin >> x[i] >> y[i] >> z[i]; }

    int ans = 0;
    REP(k, 8) {
        vector<int> v(N);
        REP(i, N) {
            auto& ts = s[k];
            v[i] = ts.x * x[i] + ts.y * y[i] + ts.z * z[i];
        }
        sort(v.begin(), v.end(), greater<int>());

        int tmp = 0;
        REP(i, M) { tmp += v[i]; }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
