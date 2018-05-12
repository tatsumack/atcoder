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
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
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

int N, M;
int p[100005];

signed main() {
    cin >> N >> M;
    REPS(i, N) cin >> p[i];

    UnionFind uf(N + 1);
    REPS(i, M) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }

    int ans = 0;
    REPS(i, N) {
        if (uf.same(i, p[i])) ++ans;
    }
    cout << ans << endl;
    return 0;
}
