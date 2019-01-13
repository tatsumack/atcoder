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
#define INF (LLONG_MAX - 1e5)
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N), B(N), p;
    stack<int> m;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        cin >> B[i];
    }
    REP(i, N) {
        int d = A[i] - B[i];
        if (d > 0) {
            p.push_back(d);
        } else if (d < 0) {
            m.push(-d);
        }
    }
    sort(p.begin(), p.end(), greater<int>());

    if (m.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int mnum = m.size();
    int ans = 0;
    REP(i, p.size()) {
        if (m.empty()) break;

        int v = p[i];
        while (v > 0) {
            if (m.empty()) break;
            int t = m.top();
            m.pop();
            if (v - t >= 0) {
                v -= t;
            } else {
                t -= v;
                m.push(t);
                v = 0;
            }
        }
        ans++;
    }

    if (m.empty()) {
        cout << ans + mnum << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
