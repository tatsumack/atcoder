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

    vector<vector<int>> G;
    vector<int> size;
    vector<int> ans;

    int dfs(int v, int p) {
        int res = 1;
        for (auto to : G[v]) {
            if (to == p) continue;
            res += dfs(to, v);
        }
        return size[v] = res;
    }

    void dfs2(int v, int pv, int p) {
        int res = pv;
        int sum = pv;
        for (auto to : G[v]) {
            if (to == p) continue;
            res = max(res, size[to]);
            sum += size[to];
        }
        ans[v] = res;
        for (auto to : G[v]) {
            if (to == p) continue;
            dfs2(to, sum + 1 - size[to], v);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        G.resize(n);
        size.resize(n);
        ans.resize(n);
        REP(i, n - 1) {
            int p;
            cin >> p;
            G[i + 1].push_back(p);
            G[p].push_back(i + 1);
        }

        dfs(0, -1);

        dfs2(0, 0, -1);
        for (auto a : ans) {
            cout << a << endl;
        }
    }
};
