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

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int u, v, du, dv;
    vector<vector<int>> G;

    void dfs(int k, int p, int d, int& g, int& dg) {
        if (d > dg) {
            g = k;
            dg = d;
        }
        for (auto to : G[k]) {
            if (to == p) continue;
            dfs(to, k, d + 1, g, dg);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        G.resize(n);
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        du = 0, dv = 0;
        dfs(0, -1, 0, u, du);
        dfs(u, -1, 0, v, dv);
        cout << u + 1 << " " << v + 1 << endl;
    }
};
