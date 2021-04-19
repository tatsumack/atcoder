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
typedef atcoder::modint1000000007 mint;

class DNowhereP {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, P;
        cin >> N >> P;
        mint res = P - 1;
        res *= atcoder::pow_mod(P - 2, N - 1, 1e9 + 7);
        cout << res.val() << endl;
    }
};
