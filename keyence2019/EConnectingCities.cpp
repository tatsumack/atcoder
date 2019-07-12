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

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;
    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return vsize[find(x)]; }
};

typedef pair<int, int> P;
struct SegmentTree {
private:
    int n;
    vector<P> node;

public:
    SegmentTree(vector<P> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, {INF, -1});
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, P val) {
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    P getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return {INF, -1};
        if (a <= l && r <= b) return node[k];

        P vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        P vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

typedef pair<int, int> P;

class EConnectingCities {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N, D;
    struct E {
        int cost, from, to;
        E(int cost, int from, int to) : cost(cost), from(from), to(to) {};
    };


    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> D;
        vector<int> A(N);
        vector<P> OA(N);
        REP(i, N) {
            cin >> A[i];
            OA[i] = {A[i], i};
        }

        vector<E> edges;
        vector<P> v(N, {INF, -1});
        SegmentTree left(v), right(v);
        sort(OA.begin(), OA.end());
        for (auto kv : OA) {
            int i = kv.second;
            int t = left.getmin(0, i).second;
            if (t >= 0) {
                int cost = (i - t) * D + A[i] + A[t];
                edges.emplace_back(cost, i, t);
            }
            t = right.getmin(i, N).second;
            if (t >= 0) {
                int cost = (t - i) * D + A[i] + A[t];
                edges.emplace_back(cost, i, t);
            }

            left.update(i, {(N - i) * D + A[i], i});
            right.update(i, {i * D + A[i], i});
        }

        auto sorter = [](const E& l, const E& r) {
            return l.cost < r.cost;
        };
        sort(edges.begin(), edges.end(), sorter);

        int res = 0;
        UnionFind uf(N);
        REP(i, edges.size()) {
            auto e = edges[i];
            if (uf.same(e.from, e.to)) continue;

            res += e.cost;
            uf.unite(e.from, e.to);
        }
        cout << res << endl;
    }
};
