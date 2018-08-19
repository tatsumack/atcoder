
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
    map<int, int> cnt;
    cnt[0] = 1;
    cnt[24] = 1;
    REP(i, N) {
        int d;
        cin >> d;
        cnt[d]++;
        cnt[24 - d]++;
    }

    if (cnt[0] > 1) {
        cout << 0 << endl;
        return 0;
    }

    // 右回り
    bool useNext = true;
    vector<int> r;
    FOR(i, 0, 24) {
        if (cnt.count(i) == 0) continue;
        if (cnt[i] >= 3) {
            cout << 0 << endl;
            return 0;
        }
        if (cnt[i] == 2 || i == 12 || i == 24) {
            r.push_back(i);
            continue;
        }
        if (cnt[i] == 1) {
            if (useNext) {
                r.push_back(i);
                useNext = false;
            }
            else
            {
                useNext = true;
            }
        }
    }

    int rans = INF;
    REP(i, r.size() - 1) {
        rans = min(rans, abs(r[i+1] - r[i]));
    }

    // 左回り
    useNext = true;
    vector<int> l;
    REV(i, 24, 0) {
        if (cnt.count(i) == 0) continue;
        if (cnt[i] >= 3) {
            cout << 0 << endl;
            return 0;
        }
        if (cnt[i] == 2 || i == 12 || i == 0) {
            l.push_back(i);
            continue;
        }
        if (cnt[i] == 1) {
            if (useNext) {
                l.push_back(i);
                useNext = false;
            }
            else
            {
                useNext = true;
            }
        }
    }

    int lans = INF;
    REP(i, l.size() - 1) {
        lans = min(lans, abs(l[i+1] - l[i]));
    }

    int ans = max(lans, rans);
    cout << ans << endl;

    return 0;
}
