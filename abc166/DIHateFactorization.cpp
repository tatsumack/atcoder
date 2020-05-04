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

class DIHateFactorization {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int X;
        cin >> X;

        vector<int> fact(100005);
        map<int, int> m;
        FOR(i, 0, 1000) {
            fact[i] = 1;
            REP(j, 5) {
                fact[i] *= i;
            }
            m[fact[i]] = i;
        }
        FOR(i, 1, 100000) {
            int a5 = fact[i];
            int b5 = a5 - X;
            int sign = 1;
            if (b5 < 0) {
                b5 *= -1;
                sign = -1;
            }
            if (m.count(b5)) {
                cout << i << " " << sign * m[b5] << endl;
                return;
            }
        }
    }
};
