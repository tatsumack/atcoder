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

int N, A[200005], sum[200005];

typedef pair<int, int> P;
P digit[30];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> A[i];

    REP(j, 30) {
        P& d = digit[j];
        if (A[0] >> j & 1) {
            d.first = 1;
            d.second = 0;
        }
    }
    sum[0] = 1;
    REPS(i, N - 1) {
        int maxl = -1;
        REP(j, 30) {
            P& d = digit[j];
            if ((A[i] >> j & 1) && d.first == 1) {
                maxl = max(maxl, d.second);
            }
            if (A[i] >> j & 1) {
                d.first = 1;
                d.second = i;
            }
        }

        if (maxl >= 0 && maxl == i - 1) {
            sum[i] = 1;
        } else if (maxl >= 0) {
            sum[i] = i - maxl;
        } else {
            sum[i] = sum[i - 1] + 1;
        }

        if (maxl == -1) continue;
        REP(j, 30) {
            P& d = digit[j];
            if (d.second < maxl) {
                d.first = 0;
                d.second = 0;
            }
        }
    }

    int ans = 0;
    REP(i, N) ans += sum[i];
    cout << ans << endl;

    return 0;
}
