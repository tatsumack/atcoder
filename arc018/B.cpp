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

class B {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            v[i] = {x, y};
        }
        sort(v.begin(), v.end());

        int res = 0;
        REP(i, N - 2) {
            FOR(j, i + 1, N - 2) {
                FOR(k, j + 1, N - 1) {
                    int x1, y1, x2, y2, x3, y3;
                    tie(x1, y1) = v[i];
                    tie(x2, y2) = v[j];
                    tie(x3, y3) = v[k];

                    int s = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
                    if (s > 0 && s % 2 == 0) {
                        res++;
                    }
                }
            }
        }
        cout << res << endl;
    }
};
