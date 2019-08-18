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

class CCleaning {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;
    vector<int> A;

    int dfs(int v, int p) {
        if (G[v].size() == 1 && p != -1) {
            return A[v];
        }

        int edges = 0;
        int maxe = -1;
        REP(i, G[v].size()) {
            int c = G[v][i];
            if (c == p) continue;
            int e = dfs(c, v);
            if (e == -1)
                return -1;
            edges += e;
            maxe = max(maxe, e);
        }

        int r = 2 * A[v] - edges;
        if (r < 0) {
            return -1;
        }

        maxe = max(maxe, r);
        if (maxe > A[v]) {
            return -1;
        }

        return r;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        A.resize(N);
        G.resize(N);
        REP(i, N) cin >> A[i];
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        if (N == 2) {
            if (A[0] == A[1]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return;
        }

        int root = 0;
        while (G[root].size() == 1) root++;

        int res = dfs(root, -1);
        if (res == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
};
