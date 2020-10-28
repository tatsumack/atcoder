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

const int mod = 998244353;

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

istream& operator>>(istream& i, mint& a) {
    i >> a.x;
    return i;
}

ostream& operator<<(ostream& o, const mint& a) {
    o << a.x;
    return o;
}

class DPowers {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        vector<mint> Z(K + 1);
        vector<mint> sub(K + 1);
        Z[0] = N;
        sub[0] = N;

        mint kfact = 1;
        vector<mint> afact(N, 1);
        vector<mint> a2fact(N, 1);
        FOR(k, 1, K) {
            kfact *= k;
            REP(i, N) {
                afact[i] *= A[i];
                Z[k] += afact[i];

                a2fact[i] *= 2 * A[i];
                sub[k] += a2fact[i];
            }
            Z[k] /= kfact;
        }

        mint xfact = 1;
        FOR(x, 1, K) {
            xfact *= x;
            mint res = 0;
            REP(k, x + 1) {
                res += Z[k] * Z[x - k];
            }
            mint ans = (xfact * res - sub[x]) / 2;
            cout << ans << endl;
        }
    }
};
