
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

    int n, k;
    cin >> n >> k;

    vector<int> L;
    vector<int> R;
    REP(i, n) {
        int x;
        cin >> x;
        if (x < 0)
        {
            L.push_back(x);
        } else
        {
            R.push_back(x);
        }
    }
    sort(L.begin(), L.end(), greater<int>());
    sort(R.begin(), R.end());

    // left
    int ans = INF;
    FOR(i, 1, k) {
        if (i > L.size()) break;
        int lans = 0;
        lans += abs(L[i-1]);
        if (i < k) {
            if (k - i - 1 >= R.size()) continue;
            lans += 2 * R[k - i - 1];
        }
        ans = min(ans, lans);
    }

    FOR(i, 1, k) {
        if (i > R.size()) break;
        int rans = 0;
        rans += abs(R[i-1]);
        if (i < k) {
            if (k - i - 1 >= L.size()) continue;
            rans += 2 * abs(L[k - i - 1]);
        }
        ans = min(ans, rans);
    }

    cout << ans << endl;

    return 0;
}
