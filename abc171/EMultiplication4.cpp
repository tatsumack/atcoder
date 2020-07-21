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

class EMultiplication4 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        vector<int> plus, minus;
        int zero = 0;
        REP(i, N) {
            if (A[i] > 0) plus.push_back(A[i]);
            if (A[i] < 0) minus.push_back(-A[i]);
        }
        sort(plus.rbegin(), plus.rend());
        sort(minus.rbegin(), minus.rend());
        mint ans = 1;
        if (plus.size() + minus.size() / 2 * 2 >= K && (K % 2 == 0 || plus.size() > 0)) {
            int p = 0;
            if (K & 1) {
                ans = plus[p++];
            }
            vector<int> v;
            for (; p + 1 < plus.size(); p += 2) v.push_back(plus[p] * plus[p + 1]);
            for (int m = 0; m + 1 < minus.size(); m += 2) v.push_back(minus[m] * minus[m + 1]);
            sort(v.rbegin(), v.rend());
            REP(i, K / 2) ans *= v[i];
        } else {
            REP(i, N) A[i] = abs(A[i]);
            sort(A.begin(), A.end());
            REP(i, K) ans *= A[i];
            ans *= -1;
        }
        cout << ans.get() << endl;
    }
};
