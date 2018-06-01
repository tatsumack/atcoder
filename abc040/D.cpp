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
    int getSize(int x) { return vsize[find(x)]; }
};

int N, M, Q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    UnionFind uf(N + 1);

    vector<pair<int, pair<int, int> > > ve;
    REP(i, M) {
        int a, b, y;
        cin >> a >> b >> y;
        ve.push_back({y, {a, b}});
    }
    sort(ve.begin(), ve.end());

    vector<pair<pair<int, int>, int> > vq;
    cin >> Q;
    REP(i, Q) {
        int v, w;
        cin >> v >> w;
        vq.push_back({{w, v}, i});
    }
    sort(vq.begin(), vq.end());

    vector<int> ans(vq.size());
    int y = M - 1;
    REV(q, Q - 1, 0) {
        auto wv = vq[q];
        int w = wv.first.first;
        while (y >= 0 && ve[y].first > w) {
            auto cities = ve[y].second;
            uf.unite(cities.first, cities.second);
            y--;
        }
        ans[wv.second] = uf.getSize(wv.first.second);
    }
    REP(i, Q) { cout << ans[i] << endl; }

    return 0;
}
