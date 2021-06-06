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

class ARockPaperScissors {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << x << endl;
            return;
        }

        set<int> s;
        s.insert(x);
        s.insert(y);
        REP(i, 3) {
            if (s.count(i) == 0) {
                cout << i << endl;
                return;
            }
        }
    }
};
