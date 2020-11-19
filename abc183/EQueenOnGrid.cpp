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


class EQueenOnGrid {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;

        vector<vector<char>> S(H, vector<char>(W));
        REP(i, H) {
            REP(j, W) {
                cin >> S[i][j];
            }
        }

        vector<vector<mint>> dp(H+1, vector<mint>(W+1));
        vector<vector<mint>> suml(H+1, vector<mint>(W+1));
        vector<vector<mint>> sumu(H+1, vector<mint>(W+1));
        vector<vector<mint>> sumlu(H+1, vector<mint>(W+1));

        dp[1][1] = 1;
        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '#') continue;
                if (i != 0 || j != 0) {
                    dp[i+1][j+1] = suml[i+1][j] + sumu[i][j+1] + sumlu[i][j];
                }
                suml[i+1][j+1] = suml[i+1][j] + dp[i+1][j+1];
                sumu[i+1][j+1] = sumu[i][j+1] + dp[i+1][j+1];
                sumlu[i+1][j+1] = sumlu[i][j] + dp[i+1][j+1];
            }
        }
        cout << dp[H][W].x << endl;
    }
};
