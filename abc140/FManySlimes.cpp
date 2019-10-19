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

class FManySlimes {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> s(1 << n);
        REP(i, 1 << n) cin >> s[i];
        sort(s.begin(), s.end());

        multiset<int> ms;
        REP(i, (1 << n) - 1) ms.insert(s[i]);

        vector<int> cur;
        cur.push_back(s.back());
        REP(i, n) {
            vector<int> next = cur;
            for (int t: cur) {
                auto itr = ms.lower_bound(t);
                if (itr == ms.begin()) {
                    cout << "No" << endl;
                    return;
                }
                itr--;
                next.push_back(*itr);
                ms.erase(itr);
            }

            sort(next.rbegin(), next.rend());
            swap(cur, next);
        }
        cout << "Yes" << endl;
    }
};
