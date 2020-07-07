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

        vector<pair<int, int>> v;
        int plus, minus, zero;
        plus = minus = zero = 0;
        REP(i, N) {
            v.push_back({abs(A[i]), A[i] >= 0 ? 1 : -1});
            if (A[i] == 0) zero++;
            if (A[i] > 0) plus++;
            if (A[i] < 0) minus++;
        }
        if (minus == N && K % 2 == 1) {
            sort(v.begin(), v.end());
            mint res = 1;
            REP(i, K) res *= -v[i].first;
            cout << res.get() << endl;
            return;
        }
        if (plus + minus < K) {
            cout << 0 << endl;
            return;
        }
        sort(v.rbegin(), v.rend());

        vector<int> cand;
        int num = 0;
        pair<int, int> m = {0, -1};
        REP(i, N) {
            if (num == K) break;
            int val, sign;
            tie(val, sign) = v[i];
            if (sign > 0) {
                cand.push_back(val);
                num++;
            }
            if (sign < 0) {
                if (m.first > 0) {
                    if (num + 2 <= K) {
                        cand.push_back(m.first);
                        cand.push_back(val);
                        m = {0, -1};
                        num += 2;
                    }
                } else {
                    m = {val, i};
                }
            }
        }
        if (m.first > 0 && K >= 2) {
            int next = -1;
            for (int i = m.second + 1; i < N; i++) {
                if (v[i].second < 0) {
                    next = v[i].first;
                    break;
                }
            }
            int tmp = cand.size();
            if (next != -1 && m.first * next > cand[tmp - 1] * cand[tmp - 2]) {
                cand.pop_back();
                cand.pop_back();
                cand.push_back(m.first);
                cand.push_back(next);
            }
        }
        if (cand.size() != K) cand.push_back(-m.first);
        mint res = 1;
        REP(i, K) res *= cand[i];
        cout << res.get() << endl;
    }
};
