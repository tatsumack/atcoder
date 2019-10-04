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

class FPure {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;

        G = vector<vector<int>>(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
        }

        int ans = INF;
        vector<int> res;
        // 最小最短閉路
        REP(i, N) {
            queue<int> q;
            q.push(i);
            vector<int> d(N, -1), prev(N, -1);
            d[i] = 0;
            bool ok = false;
            while (!ok && !q.empty()) {
                int v = q.front();
                q.pop();
                for (auto to : G[v]) {
                    if (to == i) {
                        int n = d[v] + 1;
                        if (n < ans) {
                            ans = n;
                            res.clear();
                            while (v != i) {
                                res.push_back(v);
                                v = prev[v];
                            }
                            res.push_back(i);
                        }
                        ok = true;
                        break;
                    } else if (d[to] == -1) {
                        q.push(to);
                        d[to] = d[v] + 1;
                        prev[to] = v;
                    }
                }
            }
        }
        if (ans == INF) {
            cout << -1 << endl;
            return;
        }
        cout << res.size() << endl;
        REP(i, res.size()) cout << res[i] + 1 << endl;
    }
};
