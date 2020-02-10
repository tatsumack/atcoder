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

class ARemainingBalls {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s, t, u;
        cin >> s >> t;
        int a, b;
        cin >> a >> b;
        cin >> u;
        if (s == u) a--;
        if (t == u) b--;
        cout << a << " " << b << endl;

    }
};
