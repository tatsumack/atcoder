#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef atcoder::modint998244353 mint;

// 素因数
vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            s.push_back(i);
            a /= i;
        }
    }
    if (a > 1) s.push_back(a);
    return s;
}

struct combination {
    vector<mint> fact, ifact;

    combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

struct permutation {
    vector<mint> fact, ifact;

    permutation(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }
};

class CMultipleSequences {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;

        combination cb(N + M);

        mint res = 0;
        FOR(i, 1, M) {
            auto v = getPrimeFactors(i);
            map<int, int> cnt;
            for (auto n : v) cnt[n]++;
            mint tmp = 1;
            for (auto kv : cnt) {
                tmp *= cb(N - 1 + kv.second, kv.second);
            }
            res += tmp;
        }
        cout << res.val() << endl;
    }
};
