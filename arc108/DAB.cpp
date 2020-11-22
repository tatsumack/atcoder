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
const int mod = 1e9 + 7;

struct mint {
    int x;

    mint() : x(0) {}

    mint(int x) : x((x % mod + mod) % mod) {}

    // mint(ll x):x(x){}
    mint& fix() {
        x = (x % mod + mod) % mod;
        return *this;
    }

    mint operator-() const { return mint(0) - *this; }

    mint operator~() const { return mint(1) / *this; }

    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator-=(const mint& a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator*=(const mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint& operator/=(const mint& a) {
        (x *= a.pow(mod - 2).x) %= mod;
        return *this;
    }

    mint operator+(const mint& a) const { return mint(*this) += a; }

    mint operator-(const mint& a) const { return mint(*this) -= a; }

    mint operator*(const mint& a) const { return mint(*this) *= a; }

    mint operator/(const mint& a) const { return mint(*this) /= a; }

    mint pow(int t) const {
        if (!t) return 1;
        mint res = pow(t / 2);
        res *= res;
        return (t & 1) ? res * x : res;
    }

    bool operator<(const mint& a) const { return x < a.x; }

    bool operator==(const mint& a) const { return x == a.x; }
};

class DAB {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        char caa, cab, cba, cbb;
        cin >> caa >> cab >> cba >> cbb;
        if (N == 1) {
            cout << 1 << endl;
            return;
        }
        if (cab == 'A' && caa == 'A') {
            cout << 1 << endl;
            return;
        }
        if (cab == 'B' && cbb == 'B') {
            cout << 1 << endl;
            return;
        }
        vector<vector<vector<mint>>> dp(N, vector<vector<mint>>(2, vector<mint>(2)));
        dp[1][0][0] = 1;
        dp[1][1][0] = 1;
        for (int i = 1; i < N - 1; i++) {
            if (caa == 'A') {
                dp[i + 1][0][0] += dp[i][0][0];
            } else {
                dp[i + 1][0][1] += dp[i][1][0];
            }
            if (cab == 'A') {
                dp[i + 1][1][0] += dp[i][0][0];
            } else {
                dp[i + 1][1][1] += dp[i][1][0];
            }
            if (cba == 'A') {
                dp[i + 1][0][0] += dp[i][0][1];
            } else {
                dp[i + 1][0][1] += dp[i][1][1];
            }
            if (cbb == 'A') {
                dp[i + 1][1][0] += dp[i][0][1];
            } else {
                dp[i + 1][1][1] += dp[i][1][1];
            }
        }
        mint res = dp[N-1][1][0] + dp[N-1][1][1];
        cout << res.x << endl;
    }
};
