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

int N, M;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    UnionFind uf(N + M + 2);
    REP(i, N) {
        int K;
        cin >> K;
        REP(k, K) {
            int l;
            cin >> l;
            uf.unite(i, N + l);
        }
    }

    int par = -1;
    REP(i, N) {
        if (par != -1 && par != uf.find(i)) {
            cout << "NO" << endl;
            return 0;
        }
        par = uf.find(i);
    }
    cout << "YES" << endl;

    return 0;
}
