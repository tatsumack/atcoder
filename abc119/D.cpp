
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
#include <queue>

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

int calc(int x, vector<int>& d) {
    int tt = lower_bound(d.begin(), d.end(), x) - d.begin();
    int res = abs(x - d[tt]);
    if (tt > 0) {
        res = min(res, abs(x - d[tt - 1]));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int> s(A);
    vector<int> t(B);
    vector<int> m(A + B);
    map<int, int> kind;
    REP(i, A) {
        cin >> s[i];
        m[i] = s[i];
        kind[s[i]] = 0;
    }
    REP(i, B) {
        cin >> t[i];
        m[i + A] = t[i];
        kind[t[i]] = 1;
    }
    sort(m.begin(), m.end());

    while (Q--) {
        int x;
        cin >> x;
        int res = 0;
        int tt = lower_bound(m.begin(), m.end(), x) - m.begin();
        res += abs(m[tt] - x);
        if (kind[m[tt]] == 0) {
            res += calc(m[tt], t);
        }
        else {
            res += calc(m[tt], s);
        }

        if (tt > 0) {
            int tmp = abs(x - m[tt - 1]);
            if (kind[m[tt - 1]] == 0) {
                tmp += calc(m[tt - 1], t);
            }
            else {
                tmp += calc(m[tt - 1], s);
            }
            res = min(tmp, res);
        }
        cout << res << endl;
    }
    return 0;
}
