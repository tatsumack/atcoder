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

class ESecondSum {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> pos(N + 1);
        REP(i, N) {
            int n;
            cin >> n;
            pos[n] = i + 1;
        }
        int res = 0;
        set<int> s;
        s.insert(0);
        s.insert(N + 1);
        REV(n, N, 1) {
            int p = pos[n];
            if (n != N) {
                {
                    auto itr = s.upper_bound(p);
                    if (itr != s.end()) {
                        int rr = *itr;
                        itr++;
                        int r = itr != s.end() ? *itr : N + 1;

                        itr = s.upper_bound(p);
                        itr--;
                        int l = *itr;
                        res += (r - rr) * (p - l) * n;
                    }
                }
                {
                    auto itr = s.upper_bound(p);
                    itr--;
                    if (itr != s.begin()) {
                        int ll = *itr;
                        itr--;
                        int l = *itr;

                        itr = s.upper_bound(p);
                        int r = *itr;
                        res += (r - p) * (ll - l) * n;
                    }
                }
            }
            s.insert(p);
        }
        cout << res << endl;

    }
};
