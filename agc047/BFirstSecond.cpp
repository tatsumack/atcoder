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

struct RollingHash {
    vector<int64_t> hash;
    vector<int64_t> base_pow;
    int64_t base, mod;
    const int64_t DEFAULT_BASE = 1009, DEFAULT_MOD = 1e9 + 7;

    RollingHash(string S = "", int64_t base_ = -1, int64_t mod_ = -1) {
        base = base_ > 0 ? base_ : DEFAULT_BASE;
        mod = mod_ > 0 ? mod_ : DEFAULT_MOD;
        if (S.size() > 0) initialize(S);
    }

    void initialize(string& S) {
        int N = S.size();
        vector<int> s(N);
        for (int i = 0; i < N; i++) s[i] = S[i];
        initialize(s);
    }

    void initialize(vector<int>& S) {
        hash.resize(S.size() + 1);
        base_pow.resize(S.size() + 1);
        hash[0] = 0;
        base_pow[0] = 1;
        for (int i = 1; i <= S.size(); i++) {
            hash[i] = (hash[i - 1] * base + S[i - 1]) % mod;
            base_pow[i] = base_pow[i - 1] * base % mod;
        }
    }

    // 0-indexed, [a, b)
    int64_t between(int a, int b) {
        return (mod + hash[b] - hash[a] * base_pow[b - a] % mod) % mod;
    }
};


class BFirstSecond {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<string> S(N);
        REP(i, N) {
            cin >> S[i];
            reverse(S[i].begin(), S[i].end());
        }
        sort(S.begin(), S.end(), [](auto const& lhs, auto const& rhs) {
            return lhs.size() < rhs.size();
        });
        map<int, int[26]> m;
        int res = 0;
        for (auto& s : S) {
            RollingHash rh1(s), rh2(s, 2009, 1e9 + 9);
            vector<int> cnt(26);
            for (int i = s.size() - 1; i >= 0; i--) {
                int hash1 = rh1.between(0, i);
                int hash2 = rh2.between(0, i);
                int hh = hash1 * (1e9 + 9) + hash2;
                cnt[s[i] - 'a']++;
                REP(i, 26) {
                    if (cnt[i] == 0) continue;
                    res += m[hh][i];
                }
            }
            int h1 = rh1.between(0, s.size() - 1);
            int h2 = rh2.between(0, s.size() - 1);
            int hh = h1 * (1e9 + 9) + h2;
            m[hh][s.back() - 'a']++;
        }
        cout << res << endl;
    }
};
