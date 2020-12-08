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

class DIncrementOfCoins {
public:
    map<tuple<int, int, int>, double> memo;

    double f(int a, int b, int c) {
        if (a == 100) return 0;
        if (b == 100) return 0;
        if (c == 100) return 0;
        if (memo.count({a, b, c})) return memo[{a, b, c}];
        double res = 0;
        if (a > 0) res += (double) a / (double) (a + b + c) * (f(a + 1, b, c) + 1);
        if (b > 0) res += (double) b / (double) (a + b + c) * (f(a, b + 1, c) + 1);
        if (c > 0) res += (double) c / (double) (a + b + c) * (f(a, b, c + 1) + 1);
        return memo[{a, b, c}] = res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, C;
        cin >> A >> B >> C;
        double ans = f(A, B, C);
        fcout << ans << endl;
    }
};
