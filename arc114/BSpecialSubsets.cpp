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

int prime[55];
bool is_prime[55];

int sieve(int n) {
    int p = 0;
    REP(i, n) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class ANotCoprime {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> X(N);
        REP(i, N) {
            cin >> X[i];
        }
        int n = sieve(52);
        int res = INF;
        REP(bit, 1LL << n) {
            if (bit == 0) continue;
            int t = 1;
            REP(j, n) {
                if (bit >> j & 1) {
                    t *= prime[j];
                }
            }
            bool ok = true;
            REP(i, N) {
                if (gcd(X[i], t) == 1) {
                    ok = false;
                }
            }
            if (ok) {
                res = min(res, t);
            }
        }

        cout << res << endl;
    }
};
