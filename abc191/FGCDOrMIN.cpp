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

// 約数列挙
vector<int> get(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class FGCDOrMIN {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        int mina = INF;
        map<int, int> m;
        REP(i, N) {
            for (auto n : get(A[i])) {
                if (m.count(n) == 0) {
                    m[n] = A[i];
                } else {
                    m[n] = gcd(m[n], A[i]);
                }
            }
            mina = min(mina, A[i]);
        }
        int res = 0;
        for (auto kv : m) {
            if (kv.second <= mina && kv.first == kv.second) {
                res++;
            }
        }
        cout << res << endl;
    }
};
