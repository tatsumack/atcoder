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

class EHopscotchAddict {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N, M, S, T;
    vector<vector<int>> G;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        G.resize(3 * (N + 1));
        REP(i, M) {
            int u, v;
            cin >> u >> v;
            G[u * 3].push_back(v * 3 + 1);
            G[u * 3 + 1].push_back(v * 3 + 2);
            G[u * 3 + 2].push_back(v * 3);
        }
        cin >> S >> T;

        queue<P> q;
        map<int, bool> used;
        q.push({S * 3, 0});

        vector<int> dist(3 * (N+1), INF);
        while (!q.empty()) {
            auto kv = q.front();
            q.pop();
            if (used[kv.first]) continue;
            used[kv.first] = true;
            dist[kv.first] = kv.second;
            REP(i, G[kv.first].size()) {
                int t = G[kv.first][i];
                if (used[t]) continue;
                q.push({t, kv.second + 1});
            }
        }

        int res = dist[T * 3];
        if (res == INF) {
            cout << -1 << endl;
            return;
        }
        cout << res / 3 << endl;
    }
};
