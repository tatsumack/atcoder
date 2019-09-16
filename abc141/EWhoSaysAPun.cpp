#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

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

class EWhoSaysAPun {
public:
    static constexpr int kStressIterations = 1;

    static void generateTest(std::ostream& test) {
        string tmp;
        REP(i, 5000) tmp += "a";
        test << 5000 << endl;
        test << tmp << endl;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        RollingHash rh1(s), rh2(s, 2009, 1e9 + 9);

        int l = 0;
        int r = 5000;
        while (r - l > 1) {
            int len = (r + l) / 2;
            if (len == 0) break;
            set<pair<int64_t, int64_t>> s;
            bool found = false;
            REP(i, N - len + 1) {
                if (i >= len) {
                    s.insert({rh1.between(i - len, i), rh2.between(i - len, i)});
                }
                if (s.count({rh1.between(i, i + len), rh2.between(i, i + len)})) {
                    found = true;
                    break;
                }
            }
            if (found) {
                l = len;
            } else {
                r = len;
            }
        }
        cout << l << endl;

    }
};
