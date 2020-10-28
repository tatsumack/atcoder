#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

// mod
int mod = 998244353;

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


class FKnapsackForAllSegments {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, S;
        cin >> N >> S;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(S+1, vector<mint>(3, 0)));

        dp[0][0][0] = 1;
        REP(i, N) {
            FOR(j, 0, S) {
                dp[i + 1][j][0] += dp[i][j][0];
                int nj = j + A[i];
                if (nj <= S) {
                    dp[i + 1][nj][1] += dp[i][j][0] * (i + 1);
                    dp[i + 1][nj][2] += dp[i][j][0] * (i + 1) * (N - i);
                }

                dp[i + 1][j][1] += dp[i][j][1];
                if (nj <= S) {
                    dp[i + 1][nj][1] += dp[i][j][1];
                    dp[i + 1][nj][2] += dp[i][j][1] * (N - i);
                }

                dp[i + 1][j][2] += dp[i][j][2];
            }
        }

        cout << dp[N][S][2].get() << endl;
    }
};
