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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (LLONG_MAX - 1e5)

using namespace std;

int c, r;
char C[2500];

int V;
vector<int> G[2500];
int match[2500];
bool used[2500];

void addEdge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v) {
    used[v] = true;
    REP(i, G[v].size()) {
        int u = G[v][i];
        int w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartiteMatching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    REP(v, c * r) {
        if (match[v] >= 0) continue;
        memset(used, 0, sizeof(used));
        if (dfs(v)) res++;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> c >> r;
    REP(i, c) REP(j, r) { cin >> C[i * r + j]; }

    REP(i, c) REP(j, r) {
        if (C[i * r + j] == '*') continue;
        V++;
        // 右と下だけみる
        if (i + 1 < c && C[(i + 1) * r + j] == '.')
            addEdge(i * r + j, (i + 1) * r + j);
        if (j + 1 < r && C[i * r + j + 1] == '.')
            addEdge(i * r + j, i * r + j + 1);
    }

    cout << V - bipartiteMatching() << endl;

    return 0;
}
