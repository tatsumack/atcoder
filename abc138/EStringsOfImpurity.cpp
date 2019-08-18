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

class EStringsOfImpurity {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s, t;
        cin >> s >> t;

        vector<vector<int>> pos(50);
        REP(i, s.size()) {
            char c = s[i];
            pos[c - 'a'].push_back(i + 1);
        }

        int cur = 0;
        int res = 0;
        REP(i, t.size()) {
            char c = t[i];
            const auto& v = pos[c - 'a'];
            if (v.empty()) {
                cout << -1 << endl;
                return;
            }

            auto itr = upper_bound(v.begin(), v.end(), cur);
            if (itr != v.end()) {
                int next = *itr;
                res += next - cur;
                cur = next;
            } else {
                int next = v[0];
                res += s.size() - cur;
                res += next;
                cur = next;
            }
        }
        cout << res << endl;
    }
};
