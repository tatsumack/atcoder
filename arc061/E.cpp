
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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

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

    void reset(int x) {
        par[x] = x;
        rank[x] = 0;
        vsize[x] = 1;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int getSize(int x) { return vsize[find(x)]; }
};

vector<int> G[300005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<int, vector<pair<int, int>>> C;
    REP(i, M) {
        int p, q, c;
        cin >> p >> q >> c;
        p--;
        q--;
        c--;
        C[c].push_back({p, q});
    }

    int sz = N;
    UnionFind uf(N);
    for (auto kv : C) {
        int i = kv.first;
        REP(j, C[i].size()) {
            auto p = C[i][j];
            uf.reset(p.first);
            uf.reset(p.second);
        }

        REP(j, C[i].size()) {
            auto p = C[i][j];
            uf.unite(p.first, p.second);
        }

        map<int, int> id;
        set<int> used;
        REP(j, C[i].size()) {
            auto p = C[i][j];
            int pp = uf.find(p.first);
            if (id.count(pp) == 0) id[pp] = sz++;
            if (used.count(p.first) == 0) {
                G[id[pp]].push_back(p.first);
                G[p.first].push_back(id[pp]);
            }
            if (used.count(p.second) == 0) {
                G[id[pp]].push_back(p.second);
                G[p.second].push_back(id[pp]);
            }
            used.insert(p.first);
            used.insert(p.second);
        }
    }

    vector<int> dp(sz, -1);
    queue<int> q;
    dp[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        REP(i, G[t].size()) {
            int tt = G[t][i];
            if (dp[tt] >= 0) continue;
            dp[tt] = dp[t] + 1;
            q.push(tt);
        }
    }

    if (dp[N - 1] < 0) {
        cout << -1 << endl;
    } else {
        cout << dp[N - 1] / 2 << endl;
    }
    return 0;
}
