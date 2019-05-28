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

class UGrouping {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        auto a = make_v<int>(N, N);
        REP(i, N) REP(j, N) cin >> a[i][j];

        auto score = vector<int>(1 << (N + 4));
        for (int k = 0; k < 1 << N; k++) {
            int res = 0;
            for (int l = 0; l < N; l++) {
                if ((k & (1 << l)) == 0) continue;
                for (int r = l + 1; r < N; r++) {
                    if ((k & (1 << r)) == 0) continue;
                    res += a[l][r];
                }
            }
            score[k] = res;
        }

        auto dp = vector<int>(1 << (N + 4));
        for (int j = 0; j < 1 << N; j++) {
            int sub = ((1 << N) - 1) ^ j;
            for (int k = sub; k > 0; k--) {
                k &= sub;
                dp[j | k] = max(dp[j | k], dp[j] + score[k]);
            }
        }
        cout << dp[(1 << N) - 1] << endl;
    }
};
