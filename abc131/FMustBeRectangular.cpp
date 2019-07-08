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

class FMustBeRectangular {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<P> v(N);
        vector<vector<int>> x(100005), y(100005);
        REP(i, N) {
            cin >> v[i].first >> v[i].second;
            x[v[i].first].push_back(i);
            y[v[i].second].push_back(i);
        }

        UnionFind uf(N);
        REP(i, x.size()) {
            for (int j = 0; j + 1 < x[i].size(); j++) {
                uf.unite(x[i][j], x[i][j + 1]);
            }
        }
        REP(i, y.size()) {
            for (int j = 0; j + 1 < y[i].size(); j++) {
                uf.unite(y[i][j], y[i][j + 1]);
            }
        }

        map<int, set<int>> xnum;
        map<int, set<int>> ynum;
        REP(i, N) {
            int p = uf.find(i);
            xnum[p].insert(v[i].first);
            ynum[p].insert(v[i].second);
        }

        int res = 0;
        for (auto kv : xnum) {
            int p = kv.first;
            res += xnum[p].size() * ynum[p].size();
        }
        cout << res - N << endl;

    }
};
