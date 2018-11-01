
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

    int n;
    cin >> n;
    vector<int> a(n), sum(n + 1);
    REP(i, n) {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }

    int num = 0;
    int diff = 0;
    // +-+-+-...
    REP(i, n) {
        int s = sum[i + 1] + diff;
        if (i % 2 == 0) {
            if (s <= 0) {
                diff += 1 - s;
                num += abs(1 - s);
            }
        } else {
            if (s >= 0) {
                diff += -1 - s;
                num += abs(-1 - s);
            }
        }
    }

    int ans = num;
    num = 0;
    diff = 0;
    // -+-+-+...
    REP(i, n) {
        int s = sum[i + 1] + diff;
        if (i % 2 == 1) {
            if (s <= 0) {
                diff += 1 - s;
                num += abs(1 - s);
            }
        } else {
            if (s >= 0) {
                diff += -1 - s;
                num += abs(-1 - s);
            }
        }
    }
    ans = min(ans, num);
    cout << ans << endl;

    return 0;
}
