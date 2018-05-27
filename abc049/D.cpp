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

int N, K, L;

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> L;

    UnionFind uf1(N + 1);
    UnionFind uf2(N + 1);

    REP(i, K) {
        int x, y;
        cin >> x >> y;
        uf1.unite(x, y);
    }
    REP(i, L) {
        int x, y;
        cin >> x >> y;
        uf2.unite(x, y);
    }

    map<P, int> m;
    REPS(i, N) {
        P p(uf1.find(i), uf2.find(i));
        if (m.find(p) != m.end()) {
            m[p]++;
        } else {
            m[p] = 1;
        }
    }
    REPS(i, N) {
        if (i != 1) cout << " ";
        P p(uf1.find(i), uf2.find(i));
        if (m.find(p) != m.end()) {
            cout << m[p];
        } else {
            cout << 0;
        }
    }
    cout << endl;

    return 0;
}
