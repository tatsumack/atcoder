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

int N, M;
const int MAXN = 50;
int e[MAXN][MAXN];

class GMixtureDrug {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }


    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        CLR(e, 0);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            e[a][b] = 1;
            e[b][a] = 1;
        }

        int n1 = (N + 1) / 2;
        int n2 = N - n1;

        // 最大独立集合のサイズを求める

        // 1. v1, v2の部分集合が独立集合か
        vector<bool> ok1(1 << n1, true), ok2(1 << n2, true);
        REP(i, n1) {
            REP(j, n1) {
                if (e[i][j]) {
                    ok1[(1 << i) | (1 << j)] = false;
                }
            }
        }
        REP(i, 1 << n1) {
            if (!ok1[i]) {
                REP(j, n1) {
                    ok1[i | (1 << j)] = false;
                }
            }
        }
        FOR(i, n1, N - 1) {
            FOR(j, n1, N - 1) {
                if (e[i][j]) {
                    ok2[1 << (i - n1) | 1 << (j - n1)] = false;
                }
            }
        }
        REP(i, 1 << n2) {
            if (!ok2[i]) {
                REP(j, n2) {
                    ok2[i | (1 << j)] = false;
                }
            }
        }

        // 2. v1の部分集合と辺を共有しないv2の部分集合
        vector<int> s(1 << n1);
        s[0] = (1 << n2) - 1;
        REP(i, n1) {
            s[1 << i] = (1 << n2) - 1;
            FOR(j, n1, N - 1) {
                if (e[i][j] == 0) continue;
                s[1 << i] ^= 1 << (j - n1);
            }
        }
        REP(i, 1 << n1) {
            REP(j, n1) {
                if (i & (1 << j)) continue;
                s[i | (1 << j)] = s[i] & s[1 << j];
            }
        }

        // 3. v2の部分集合の最大独立集合のサイズ
        vector<int> size2(1 << n2, 0);
        REP(i, 1 << n2) {
            if (!ok2[i]) continue;
            int sz = 0;
            REP(j, n2) {
                if (i & (1 << j)) {
                    sz++;
                }
            }
            size2[i] = sz;
        }
        REP(i, 1 << n2) {
            REP(j, n2) {
                if (i & (1 << j)) continue;
                size2[i | (1 << j)] = max(size2[i | (1 << j)], size2[i]);
            }
        }

        // 4. v1の部分集合に対して、v1・v2の最大独立集合のサイズを求める
        int res = 0;
        REP(i, 1 << n1) {
            if (!ok1[i]) continue;
            int sz1 = 0;
            REP(j, n1) {
                if ((i >> j) & 1) {
                    sz1++;
                }
            }
            int sz2 = size2[s[i]];
            res = max(res, sz1 + sz2);
        }
        cout << res << endl;
    }
};
