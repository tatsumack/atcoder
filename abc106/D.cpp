
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

    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int, int>> v;
    vector<pair<int, int>> seg(M+Q+1);

    int idx = 0;
    REP(i, M) {
        int l, r;
        cin >> l >> r;
        v.push_back({r, idx});
        seg[idx] = {l, r};
        idx++;
    }
    REP(i, Q) {
        int l, r;
        cin >> l >> r;
        v.push_back({r, idx});
        seg[idx] = {l, r};
        idx++;
    }
    sort(v.begin(), v.end());

    vector<int> n(505);
    vector<int> q(Q);
    REP(i, v.size()) {
        auto kv = v[i];
        if (kv.second < M) {
            auto tseg = seg[kv.second];
            n[tseg.first]++;
        } else {
            auto tseg = seg[kv.second];

            int ans = 0;
            FOR(j, tseg.first, tseg.second) {
                ans += n[j];
            }
            q[kv.second - M] = ans;
        }
    }

    REP(i, q.size()) {
        cout << q[i] << endl;
    }
    return 0;
}
