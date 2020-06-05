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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class EBullet {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];

        vector<mint> two(N + 1);
        two[0] = 1;
        REP(i, N) two[i + 1] = two[i] * 2;

        map<pair<int, int>, int> cnt;
        int c = 0;
        REP(i, N) {
            int a = A[i];
            int b = B[i];
            if (a == 0 && b == 0) {
                c++;
                continue;
            }
            int g = gcd(a, b);
            a /= g;
            b /= g;
            if (a < 0) {
                a *= -1;
                b *= -1;
            }
            cnt[{a, b}]++;
        }

        mint res = 1;
        for (auto kv: cnt) {
            int a, b;
            tie(a, b) = kv.first;
            if (cnt[{a, b}] == 0) continue;

            int n1 = cnt[{a,b}];
            if (b < 0) {
                a *= -1;
                b *= -1;
            }
            int n2 = cnt[{b,-a}];
            res *= two[n1] + two[n2] - 1;
            cnt[{b, -a}] = 0;
        }
        res -= 1;
        res += c;
        cout << res.get() << endl;
    }
};
