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

class FTreeAndConstraints {
public:
    vector<vector<int>> G;
    vector<P> path;
    int M;
    int N;
    bitset<50> found;

    vector<int> two;
    map<P, int> id;

    bool dfs(int u, int v, int p) {
        if (u == v) return true;
        for (auto to : G[u]) {
            if (to == p) continue;
            auto ok = dfs(to, v, u);
            if (ok) {
                if (u > to) swap(u, to);
                found |= 1LL << (id[{u, to}]);
                return true;
            }
        }
        return false;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        G.resize(N);
        int idx = 0;
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
            if (a > b) swap(a, b);
            id[{a, b}] = idx++;
        }
        cin >> M;
        path.resize(M);
        REP(i, M) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            path[i] = {u, v};
        }
        two.resize(N);
        two[0] = 1;
        FOR(i, 1, N - 1) two[i] = two[i - 1] * 2;

        map<int, bitset<50>> pmap;
        REP(i, M) {
            found.reset();
            dfs(path[i].first, path[i].second, -1);
            pmap[i] = found;
        }

        int res = two[N - 1];
        REP(s, 1LL << M) {
            if (s == 0) continue;
            int num = 0;
            REP(i, M) {
                if (s >> i & 1) num++;
            }
            int sign = num % 2 == 1 ? -1 : 1;

            bitset<50> tmp;
            REP(i, M) {
                if (s >> i & 1) {
                    tmp |= pmap[i];
                }
            }
            int v = two[N - 1 - tmp.count()];
            res += sign * v;
        }
        cout << res << endl;
    }
};
