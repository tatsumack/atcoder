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

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class EThrone {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int N, S, K;
            cin >> N >> S >> K;
            int g = N;
            g = gcd(g, S);
            g = gcd(g, K);
            N /= g;
            S /= g;
            K /= g;
            // S + x * K = 0 mod N
            if (gcd(K, N) != 1) {
                cout << -1 << endl;
                continue;
            }
            int val = N - S;
            cout << val * modinv(K, N) % N << endl;
        }

    }
};
