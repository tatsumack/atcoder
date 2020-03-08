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
#include <random>
#include <chrono>

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

class EDivisibleSubstring {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, P;
        cin >> N >> P;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        if (P == 2 || P == 5) {
            int res = 0;
            REP(i, N) {
                int n = s[i] - '0';
                if (n % P == 0) {
                    res += N - i;
                }
            }
            cout << res << endl;
            return;
        }

        vector<int> v(N), sum(N + 1);
        REP(i, N) {
            int n = s[i] - '0';
            v[i] = n % P;
        }

        int cur = 1;
        REP(i, N) {
            sum[i + 1] = (sum[i] + v[i] * cur) % P;
            cur *= 10;
            cur %= P;
        }

        map<int, int> cnt;
        int res = 0;
        REP(i, N + 1) {
            res += cnt[sum[i]];
            cnt[sum[i]]++;
        }
        cout << res << endl;
    }
};
