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

class DPairCards {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;

        vector<int> X(N);
        REP(i, N) cin >> X[i];

        vector<vector<int>> d(M);
        REP(i, N) {
            d[X[i] % M].push_back(X[i]);
        }

        int res = 0;
        for (int i = 0; i <= M / 2; i++) {
            auto& l = d[i];
            auto& r = d[M - i];

            if (i == 0 || i + i == M) {
                res += l.size() / 2;
                continue;
            }

            if (l.size() < r.size()) {
                swap(l, r);
            }

            int cur = l.size();
            int prev = -1;
            sort(l.begin(), l.end());
            REP(j, l.size()) {
                if (cur <= r.size() + 1) break;
                if (l[j] == prev) {
                    res += 1;
                    cur -= 2;
                    prev = -1;
                    continue;
                }
                prev = l[j];
            }
            res += r.size();
        }
        cout << res << endl;
    }
};
