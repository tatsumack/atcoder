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

class FDistributingIntegers {
public:
    vector<mint> fact;
    vector<vector<int>> G;
    vector<mint> dp;
    vector<int> num;
    vector<mint> ans;

    void dfs1(int v, int p) {
        vector<int> child;
        int sum = 0;
        for (auto to : G[v]) {
            if (to == p) continue;
            dfs1(to, v);
            child.push_back(num[to]);
            sum += num[to];
        }

        mint res = fact[sum];
        for (auto val : child) {
            res /= fact[val];
        }
        for (auto to : G[v]) {
            if (to == p) continue;
            res *= dp[to];
        }
        dp[v] = res;
        num[v] = sum + 1;
    }

    void dfs2(int v, int p) {
        vector<int> child;
        int sum = 0;
        for (auto to : G[v]) {
            child.push_back(num[to]);
            sum += num[to];
        }

        mint res = fact[sum];
        mint tmp = 1;
        mint tmp2 = 1;
        for (auto val : child) {
            res /= fact[val];
            tmp /= fact[val];
        }
        for (auto to : G[v]) {
            res *= dp[to];
            tmp2 *= dp[to];
        }
        ans[v] = res;

        for (auto to : G[v]) {
            if (to == p) continue;
            num[v] = sum - num[to] + 1;
            dp[v] = fact[sum - num[to]] * tmp * fact[num[to]] * tmp2 / dp[to];
            dfs2(to, v);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        fact.resize(N + 1);
        dp.resize(N);
        num.resize(N);
        ans.resize(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        fact[0] = 1;
        FOR(i, 1, N) fact[i] = fact[i - 1] * i;

        dfs1(0, -1);
        dfs2(0, -1);
        REP(i, ans.size()) cout << ans[i].get() << endl;
    }
};
