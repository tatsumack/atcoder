
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

int N, Q;
string s;

int goal(int pos, vector<char>& t, vector<char>& d) {
    REP(i, Q) {
        if (s[pos] == t[i]) {
            d[i] == 'L' ? pos-- : pos++;
        }

        if (pos < 0) {
            return 1;
        }

        if (pos >= N) {
            return 2;
        }
    }

    return 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;
    cin >> s;

    vector<char> t(Q), d(Q);
    REP(i, Q) {
        cin >> t[i] >> d[i];
    }

    if (goal(0, t, d) == 2 || goal(N - 1, t, d) == 1) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;

    if (goal(0, t, d) == 1) {
        int l = 0;
        int r = N - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (goal(m, t, d) == 1) {
                l = m;
            } else {
                r = m;
            }
        }

        res += l + 1;
    }

    if (goal(N - 1, t, d) == 2) {
        int l = 0;
        int r = N - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (goal(m, t, d) == 2) {
                r = m;
            } else {
                l = m;
            }
        }

        res += N - r;
    }

    cout << N - res << endl;

    return 0;
}
