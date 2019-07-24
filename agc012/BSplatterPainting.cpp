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

int color[100005][15];
vector<int> G[100005];

class BSplatterPainting {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    unordered_map<int, int> res;
    int N, M;

    void f(int from, int d, int c) {
        queue<P> q;
        q.push({from, d});

        while (!q.empty()) {
            int i, dist;
            tie(i, dist) = q.front();
            q.pop();
            if (color[i][dist] != -1) continue;
            color[i][dist] = c;
            if (res.count(i) == 0) {
                res[i] = c;
            }

            if (dist == 0) continue;
            REP(j, G[i].size()) {
                int to = G[i][j];
                if (color[to][dist - 1] != -1) continue;
                q.push({to, dist - 1});
            }
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;

        CLR(color, 0);
        REP(i, N) G[i].clear();

        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int Q;
        cin >> Q;
        struct query {
            int v, d, c;
        };
        vector<query> vq(Q);
        REP(i, Q) {
            cin >> vq[i].v >> vq[i].d >> vq[i].c;
            vq[i].v--;
        }
        reverse(vq.begin(), vq.end());

        REP(i, N) REP(j, 11) color[i][j] = -1;

        REP(i, Q) {
            f(vq[i].v, vq[i].d, vq[i].c);
        }

        REP(i, N) {
            cout << res[i] << endl;
        }
    }
};
