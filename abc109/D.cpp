
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

typedef pair<int, int> P;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;

    int a[505][505];
    CLR(a, 0);
    REP(i, H) REP(j, W) cin >> a[i][j];

    vector<pair<P, P> > ans;
    REP(i, H) REP(j, W - 1) {
            if (a[i][j] % 2 == 1) {
                a[i][j]--;
                a[i][j + 1]++;
                ans.push_back({{i, j},
                               {i, j + 1}});
            }
        }
    REP(i, H - 1) {
        if (a[i][W - 1] % 2 == 1) {
            a[i][W - 1]--;
            a[i + 1][W - 1]++;
            ans.push_back({{i,     W - 1},
                           {i + 1, W - 1}});
        }
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        auto prev = ans[i].first;
        auto next = ans[i].second;
        cout << prev.first + 1 << " " << prev.second + 1 << " " << next.first + 1 << " " << next.second + 1 << endl;
    }

    return 0;
}
