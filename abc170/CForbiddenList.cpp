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

class CForbiddenList {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int X, N;
        cin >> X >> N;
        set<int> s;
        REP(i, N) {
            int p;
            cin >> p;
            s.insert(p);
        }

        int l = X;
        int r = X;
        while (true) {
            if (s.count(l) == 0) {
                cout << l << endl;
                return;
            }
            if (s.count(r) == 0) {
                cout << r << endl;
                return;
            }
            l--, r++;
        }
    }
};
