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

int mod = 1e9 + 7;

struct mint {
    unsigned x;

    mint() : x(0) {}

    mint(signed sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }

    mint(signed long long sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }

    int get() const { return (int) x; }

    mint& operator+=(mint that) {
        if ((x += that.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator-=(mint that) {
        if ((x += mod - that.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator*=(mint that) {
        x = (unsigned long long) x * that.x % mod;
        return *this;
    }

    mint& operator/=(mint that) { return *this *= that.inverse(); }

    mint operator+(mint that) const { return mint(*this) += that; }

    mint operator-(mint that) const { return mint(*this) -= that; }

    mint operator*(mint that) const { return mint(*this) *= that; }

    mint operator/(mint that) const { return mint(*this) /= that; }

    mint inverse() const {
        long long a = x, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return mint(u);
    }

    bool operator==(mint that) const { return x == that.x; }

    bool operator!=(mint that) const { return x != that.x; }

    mint operator-() const {
        mint t;
        t.x = x == 0 ? 0 : mod - x;
        return t;
    }
};

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inverse();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};


class FCoincidence {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    mint dp[65][2][65];

    mint calc(int n, combination& c) {
        int m = -1;
        REP(i, 62) {
            if (n & (1LL << i)) {
                m = max(i, m);
            }
        }

        dp[m][0][1] = 1;
        REV(i, m - 1, 0) {
            REP(j, 60) {
                if (n & (1LL << i)) {
                    // たてる
                    dp[i][0][j + 1] += dp[i + 1][0][j];
                    dp[i][1][j + 1] += dp[i + 1][1][j];
                    // たてない
                    dp[i][0][j] += dp[i + 1][0][j];
                    dp[i][1][j] += dp[i + 1][1][j];
                    dp[i][1][j] += dp[i + 1][0][j];
                } else {
                    // たてる
                    dp[i][1][j + 1] += dp[i + 1][1][j];
                    // たてない
                    dp[i][0][j] += dp[i + 1][0][j];
                    dp[i][1][j] += dp[i + 1][1][j];
                }
            }
        }


        mint res = 0;
        FOR(i, 1, 60) {
            //DUMP(i)
            //DUMP(dp[0][0][i].get())
            //DUMP(dp[0][1][i].get())
            mint tmp = 0;
            FOR(j, 1, i) {
                tmp += c(i, j);
            }
            tmp *= (dp[0][0][i] + dp[0][1][i]);
            res += tmp;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int L, R;
        cin >> L >> R;
        combination c(30);
        CLR(dp, 0);
        mint l = calc(L - 1, c);
        CLR(dp, 0);
        mint r = calc(R, c);
        mint res = r - l;
        cout << res.get() << endl;
    }
};
