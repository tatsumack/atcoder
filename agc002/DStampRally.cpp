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
struct PartiallyPersistentUnionFind {
    vector<int> data;
    vector<int> last;
    vector<vector<pair<int, int>>> add;

    PartiallyPersistentUnionFind() {}

    PartiallyPersistentUnionFind(int sz) : data(sz, -1), last(sz, 1e9), add(sz) {
        for (auto& vs : add) vs.emplace_back(-1, -1);
    }

    bool unite(int t, int x, int y) {
        x = find(t, x);
        y = find(t, y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        add[x].emplace_back(t, data[x]);
        data[y] = x;
        last[y] = t;
        return true;
    }

    int find(int t, int x) {
        if (t < last[x]) return x;
        return find(t, data[x]);
    }

    int size(int t, int x) {
        x = find(t, x);
        return -prev(lower_bound(begin(add[x]), end(add[x]), make_pair(t, 0)))->second;
    }
};

class DStampRally {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;
        PartiallyPersistentUnionFind uf(m + 1);
        REP(i, m) {
            int a, b;
            cin >> a >> b;
            uf.unite(i + 1, a, b);
        }
        int q;
        cin >> q;
        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            int l = 0;
            int r = m;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                int sz = uf.size(mid, x);
                if (uf.find(mid, x) != uf.find(mid, y)) {
                    sz += uf.size(mid, y);
                }
                if (sz >= z) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            cout << r << endl;
        }

    }
};
