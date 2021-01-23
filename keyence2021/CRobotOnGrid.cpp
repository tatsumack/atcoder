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
const int mod = 998244353;

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

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}


class CRobotOnGrid {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, K;
        cin >> H >> W >> K;
        vector<vector<mint>> dp(H, vector<mint>(W));
        vector<vector<char>> C(H, vector<char>(W, '.'));

        REP(i, K) {
            int h, w;
            char c;
            cin >> h >> w >> c;
            h--, w--;
            C[h][w] = c;
        }

        dp[0][0] = binpow(3, H * W - K);
        REP(i, H) {
            REP(j, W) {
                switch (C[i][j]) {
                    case '.':
                        if (i + 1 < H) dp[i + 1][j] += dp[i][j] / 3 * 2;
                        if (j + 1 < W) dp[i][j + 1] += dp[i][j] / 3 * 2;
                        break;
                    case 'R':
                        if (j + 1 < W) dp[i][j + 1] += dp[i][j];
                        break;
                    case 'D':
                        if (i + 1 < H) dp[i + 1][j] += dp[i][j];
                        break;
                    case 'X':
                        if (i + 1 < H) dp[i + 1][j] += dp[i][j];
                        if (j + 1 < W) dp[i][j + 1] += dp[i][j];
                        break;
                    default:
                        break;
                }
            }
        }
        cout << dp[H - 1][W - 1].get() << endl;
    }
};
