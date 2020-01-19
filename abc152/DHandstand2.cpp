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

class DHandstand2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        map<P, int> cnt;
        FOR(i, 1, N) {
            int n = i;
            int b = n % 10;
            while (n >= 10) {
                n /= 10;
            }
            int a = n;
            if (b == 0) continue;
            cnt[{a, b}]++;
        }

        int res = 0;
        FOR(i, 1, N) {
            int n = i;
            int b = n % 10;
            while (n >= 10) {
                n /= 10;
            }
            int a = n;
            if (b == 0) continue;
            res += cnt[{b, a}];
        }
        cout << res << endl;
    }
};
