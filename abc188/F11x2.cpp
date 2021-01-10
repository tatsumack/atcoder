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

class F11x2 {
public:
    int X, Y;
    map<int, int> memo;

    int dfs(int y) {
        if (memo.count(y)) return memo[y];
        if (y == X) return 0;
        if (y <= 1) return abs(X - y);

        int res = 0;
        if (y % 2 == 0) {
            res = min({abs(X - y), dfs(y / 2) + 1});
        } else {
            res = min({abs(X - y), dfs((y + 1) / 2) + 2, dfs((y - 1) / 2) + 2});
        }
        return memo[y] = res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> X >> Y;
        if (X >= Y) {
            cout << X - Y << endl;
            return;
        }
        cout << dfs(Y) << endl;
    }
};
