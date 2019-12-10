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

class CHonestOrUnkind2 {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;

        vector<vector<P>> g(n);
        REP(i, n) {
            int a;
            cin >> a;
            REP(j, a) {
                int x, y;
                cin >> x >> y;
                x--;
                g[i].push_back({x, y});
            }
        }

        int res = 0;
        REP(i, 1 << n) {
            vector<int> s(n, -1);

            int ok = true;
            REP(j, n) {
                if ((i >> j & 1) == 0) continue;
                for(auto kv : g[j]) {
                    if (s[kv.first] != -1 && s[kv.first] != kv.second) {
                        ok = false;
                        break;
                    }
                    s[kv.first] = kv.second;
                }
            }
            if (!ok) continue;

            REP(j, n) {
                if (s[j] == -1) continue;
                int v = (i >> j & 1);
                if (v != s[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            int tmp = 0;
            REP(j, n) {
                if (i >> j & 1) tmp++;
            }
            res = max(res, tmp);
        }
        cout << res << endl;
    }
};
