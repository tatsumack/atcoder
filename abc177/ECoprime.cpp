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

// 素因数
set<int> getPrimeFactors(int a) {
    set<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.insert(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.insert(a);
    return s;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

template<typename T>
vector<T> smallest_prime_factors(T n) {

    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;


    for (T i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (T j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

template<typename T>
set<T> factolization(T x, vector<T>& spf) {
    set<T> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x /= spf[x];
    }
    return ret;
}

class ECoprime {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        vector<int> spf = smallest_prime_factors(1000005LL);

        set<int> s;
        bool ok = true;
        REP(i, N) {
            auto t = factolization(A[i], spf);
            for (auto n : t) {
                if (s.count(n)) {
                    ok = false;
                }
                s.insert(n);
            }
        }
        if (ok) {
            cout << "pairwise coprime" << endl;
            return;
        }

        int g = A[0];
        REP(i, N) {
            g = gcd(g, A[i]);
        }
        cout << (g == 1 ? "setwise coprime" : "not coprime") << endl;
    }
};
