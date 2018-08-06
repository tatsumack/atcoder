
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

bool used[11];

int D, G, p[11], b[11];

int dfs(vector<int>& v, int depth) {
    if (depth == D)
    {
        int g = G;
        int tmp = 0;
        REP(i, v.size()) {
            int t = v[i];
            int num = p[t];
            int k = g / (t*100);
            if (g % (t*100) != 0) k++;
            if (k <= num)
            {
                return tmp + k;
            } else
            {
                g -= num * (t * 100);
                g -= b[t];
                if (g <= 0) {
                    return tmp + num;
                }
                tmp += num;
            }
        }
    }

    int res = INF;
    REPS(i, D)
    {
        if (used[i]) continue;
        used[i] = true;
        v[depth] = i;
        res = min(res, dfs(v, depth + 1));
        used[i] = false;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> D >> G;
    REPS(i, D) {
        cin >> p[i] >> b[i];
    }

    vector<int> v(D);
    int ans = dfs(v, 0);
    cout << ans << endl;

    return 0;
}
