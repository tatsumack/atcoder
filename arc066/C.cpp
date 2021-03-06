
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

int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    REP(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    bool ok = true;
    if (N % 2 == 1) {
        if (a[0] != 0) {
            ok = false;
        } else {
            int cur = 2;
            for (int i = 1; i <= N - 2; i += 2) {
                if (a[i] != cur || a[i + 1] != cur) {
                    ok = false;
                    break;
                }
                cur += 2;
            }
        }
    } else {
        int cur = 1;
        for (int i = 0; i <= N - 2; i += 2) {
            if (a[i] != cur || a[i + 1] != cur) {
                ok = false;
                break;
            }
            cur += 2;
        }
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    int n = N / 2;

    int ans = 1;
    REP(i, n) {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;

    return 0;
}
