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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i > 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    UnionFind(int size) : par(size), rank(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
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
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

struct edge {
    int u, v, cost;
};

bool comp(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }

int N, E;
edge es[2 * 100005];

// クラスカル
int kruskal() {
    sort(es, es + E, comp);
    UnionFind uf(N);
    int res = 0;
    REP(i, E) {
        edge& e = es[i];
        if (!uf.same(e.u, e.v)) {
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

struct Point {
    int x, y, id;
};

bool compx(Point& p1, Point& p2) { return p1.x < p2.x; }
bool compy(Point& p1, Point& p2) { return p1.y < p2.y; }

signed main() {
    cin >> N;

    vector<Point> ps(N);
    REP(i, N) {
        Point p;
        cin >> p.x >> p.y;
        p.id = i;
        ps[i] = p;
    }

    sort(ps.begin(), ps.end(), compx);
    FOR(i, 1, N) {
        es[E].u = ps[i - 1].id;
        es[E].v = ps[i].id;
        es[E].cost = ps[i].x - ps[i - 1].x;
        E++;
    }
    sort(ps.begin(), ps.end(), compy);
    FOR(i, 1, N) {
        es[E].u = ps[i - 1].id;
        es[E].v = ps[i].id;
        es[E].cost = ps[i].y - ps[i - 1].y;
        E++;
    }

    cout << kruskal() << endl;

    return 0;
}
