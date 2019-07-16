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

class CRemainderGame {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> a, b;
    int d[51][51];

    bool ok(int s) {
        FOR(i, 0, 50) {
            FOR(j, 0, 50) {
                if (i == j) {
                    d[i][j] = 1;
                } else {
                    d[i][j] = INF;
                }
            }
        }

        FOR(i, 1, 50) {
            if (s >> i & 1) {
                FOR(j, 0, 50) {
                    d[j][j % i] = 1;
                }
            }
        }

        FOR(k, 0, 50) FOR(i, 0, 50) FOR(j, 0, 50) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        bool ok = true;
        REP(i, a.size()) {
            if (d[a[i]][b[i]] >= INF) {
                ok = false;
                break;
            }
        }

        return ok;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        a.resize(N), b.resize(N);
        REP(i, N) cin >> a[i];
        REP(i, N) cin >> b[i];

        int s = 0;
        FOR(i, 1, 50) s |= 1LL << i;

        if (!ok(s)) {
            cout << -1 << endl;
            return;
        }

        REV(i, 50, 1) {
            s ^= 1LL << i;
            if (!ok(s)) {
                s |= 1LL << i;
            }
        }

        int res = 0;
        FOR(i, 1, 50) {
            if (s >> i & 1) {
                res += 1LL << i;
            }
        }
        cout << res << endl;
    }
};
