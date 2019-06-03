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

template<typename T>
vector <T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

struct LCA {
    static const int MAX_V = 100100;
    static const int MAX_LOG_V = 21;

    vector<int> G[MAX_V];

    int parent[MAX_LOG_V][MAX_V];
    int depth[MAX_V];

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (int i = 0; i < G[v].size(); i++) {
            if (G[v][i] != p) dfs(G[v][i], v, d + 1);
        }
    }

    void init(int root, int V) {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < MAX_LOG_V; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < MAX_LOG_V; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;

        for (int k = MAX_LOG_V - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }
};

LCA lca;
class ECompleteCompress {
public:
    void solve(std::istream& cin, std::ostream& cout) {

        int N;
        cin >> N;
        string s;
        cin >> s;


        REP(i, N-1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            lca.G[a].push_back(b);
            lca.G[b].push_back(a);
        }
        vector<int> v;
        REP(i, s.size()) {
            if (s[i] == '1') v.push_back(i);

        }

        if (v.size() == 1) {
            cout << 0 << endl;
            return;
        }

        lca.init(0, N);
        int mind = INF;
        REP(i, v.size()) {
            bool ok = false;
            REP(j, v.size()) {
                if (i == j) continue;
                int a = v[i];
                int b = v[j];
                int p = lca.get(a, b);
                mind = min(mind, lca.depth[p]);

                int d = lca.depth[a] + lca.depth[b] - (lca.depth[p] - 1) * 2 - 1;
                if (d % 2 == 1) {
                    ok = true;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                return;
            }
        }

        int res = 0;
        REP(p, N) {
            REP(i, v.size()) {
                res += lca.depth[v[i]] - lca.depth[mind] - 1;
            }
        }
        cout << res << endl;

    }
};
