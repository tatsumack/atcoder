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

class DTakahashiUnevolved {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int X, Y, A, B;
        cin >> X >> Y >> A >> B;

        int res = 0;
        while (X <= (X + B) / A && X <= (Y - 1) / A) {
            res++;
            X *= A;
        }
        res += (Y - 1 - X) / B;
        cout << res << endl;
    }
};
