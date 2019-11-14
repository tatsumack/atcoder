#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

// Range Minimum Query
struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, INF);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};
class DShortestPathOnALine {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;

        vector<int> v(N, INF);
        v[0] = 0;
        SegmentTree seg(v);

        vector<int> C;
        vector<pair<P, int>> range;
        REP(i, M) {
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;
            range.push_back({{l, r}, i});
            C.push_back(c);
        }
        sort(range.begin(), range.end());

        for (auto kv : range) {
            int l, r;
            tie(l, r) = kv.first;
            int idx = kv.second;

            int cur = seg.getmin(r, r+1);
            int val = seg.getmin(l, r);
            if (val == INF) {
                continue;
            }
            if (val + C[idx] < cur)
                seg.update(r, val + C[idx]);
        }

        int res = seg.getmin(N - 1, N);
        if (res == INF) {
            cout << -1 << endl;
        } else {
            cout << res << endl;
        }
    }
};
