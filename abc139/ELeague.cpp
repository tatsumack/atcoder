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

class ELeague {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        map<P, vector<P>> G;
        map<P, int> in;
        REP(i, N) {
            P prev = {-1, -1};
            REP(j, N - 1) {
                int to;
                cin >> to;
                to--;
                int from = i;
                if (from > to) swap(from, to);
                P p = {from, to};
                if (prev.first >= 0) {
                    G[prev].push_back(p);
                    in[p]++;
                }
                if (in.count(p) == 0) {
                    in[p] = 0;
                }
                prev = p;
            }
        }

        queue<P> q;
        for (auto kv: in) {
            if (kv.second == 0) {
                q.push(kv.first);
            }
        }

        int res = 0;
        int cur = 0;
        while (!q.empty()) {
            map<int, bool> used;

            while (!q.empty()) {
                int a, b;
                tie(a, b) = q.front();
                if (used[a] || used[b]) break;
                q.pop();
                used[a] = true;
                used[b] = true;
                cur++;
                for (auto next : G[{a, b}]) {
                    in[next]--;
                    if (in[next] == 0) {
                        q.push(next);
                    }
                }
            }
            res++;
        }
        if (cur != N * (N - 1) / 2) {
            cout << -1 << endl;
            return;
        }
        cout << res << endl;
    }
};
