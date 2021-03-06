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

int mod = 1e9+7;
struct mint {
    unsigned x; mint() : x(0) { }
    mint(signed sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }
    mint(signed long long sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }
    int get() const { return (int)x; }
    mint &operator+=(mint that) { if ((x += that.x) >= mod) x -= mod; return *this; }
    mint &operator-=(mint that) { if ((x += mod - that.x) >= mod) x -= mod; return *this; }
    mint &operator*=(mint that) { x = (unsigned long long)x * that.x % mod; return *this; }
    mint &operator/=(mint that) { return *this *= that.inverse(); }
    mint operator+(mint that) const { return mint(*this) += that; }
    mint operator-(mint that) const { return mint(*this) -= that; }
    mint operator*(mint that) const { return mint(*this) *= that; }
    mint operator/(mint that) const { return mint(*this) /= that; }
    mint inverse() const {
        long long a = x, b = mod, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return mint(u);
    }
    bool operator==(mint that) const { return x == that.x; }
    bool operator!=(mint that) const { return x != that.x; }
    mint operator-() const { mint t; t.x = x == 0 ? 0 : mod - x; return t; }
};

mint dp[100005][2];

class ESumEqualsXor {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string L;
        cin >> L;

        REP(i, L.size() + 1) {
            dp[i][0] = 0;
            dp[i][1] = 0;
        }

        dp[0][0] = 1;
        REP(i, L.size()) {
            if (L[i] == '1') {
                dp[i+1][0] += dp[i][0] * 2;
                dp[i+1][1] += dp[i][0];
                dp[i+1][1] += dp[i][1] * 3;
            }
            else {
                dp[i+1][0] += dp[i][0];
                dp[i+1][1] += dp[i][1] * 3;
            }
        }
        cout << mint(dp[L.size()][0] + dp[L.size()][1]).get() << endl;
    }
};
