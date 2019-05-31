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

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

class XTower {
public:

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        auto dp = make_v<int>(1005, 30005);

        vector<int> w(N), s(N), v(N), o(N);
        REP(i, N) {
            cin >> w[i] >> s[i] >> v[i];
            o[i] = i;
        }
        sort(o.begin(), o.end(), [&](int i, int j) {
            return min(s[i], s[j] - w[i]) > min(s[j], s[i] - w[j]);
        });

        REP(i, N) {
            int t = o[i];
            REP(j, 20001) {
                // 積まない
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                // 積む
                if (j <= s[t]) {
                    dp[i + 1][j + w[t]] = max(dp[i + 1][j + w[t]], dp[i][j] + v[t]);
                }
            }
        }

        int res = 0;
        REP(j, 20001) {
            res = max(res, dp[N][j]);
        }
        cout << res << endl;

    }
};
