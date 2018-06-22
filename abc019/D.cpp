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

int N;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int maxd = 0;
    int t = 0;
    REP(i, N) {
        if (i + 1 == 1) continue;
        cout << "? 1 " << i + 1 << endl;

        int d;
        cin >> d;
        if (d > maxd) {
            t = i + 1;
            maxd = d;
        }
    }

    int ans = 0;
    REP(i, N) {
        if (i + 1 == t) continue;
        cout << "? " << t << " " << i + 1 << endl;

        int d;
        cin >> d;
        ans = max(ans, d);
    }
    cout << "! " << ans << endl;

    return 0;
}