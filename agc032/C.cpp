
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

typedef pair<int, int> P;

struct SCC {
    const int n;
    vector<vector<int>> G;
    vector<vector<int>> rG;
    vector<int> vs;
    vector<bool> used;
    vector<int> cmp;

    SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}

    void addEdge(int from, int to) {
        G[from].emplace_back(to);
        rG[to].emplace_back(from);
    }

    void dfs(int v) {
        used[v] = true;
        for (auto&& nxt : G[v]) {
            if (!used[nxt]) dfs(nxt);
        }
        vs.emplace_back(v);
    }

    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto&& nxt : rG[v]) {
            if (!used[nxt]) rdfs(nxt, k);
        }
        vs.emplace_back(v);
    }

    int scc() {
        REP(v, n)
        {
            if (!used[v]) dfs(v);
        }
        used.assign(n, false);
        int k = 0;
        for (int i = vs.size() - 1; i >= 0; i--) {
            int v = vs[i];
            if (!used[v]) rdfs(v, k++);
        }
        return k;
    }

    bool same(int a, int b) {
        return cmp[a] == cmp[b];
    }

    int get(int a) {
        return cmp[a];
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
