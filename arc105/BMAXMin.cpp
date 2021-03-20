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

class BMAXMin {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        set<int> s;
        REP(i, N) {
            int a;
            cin >> a;
            s.insert(a);
        }
        while (*s.begin() != *s.rbegin()) {
            int mi = *s.begin();
            int ma = *s.rbegin();
            s.erase(ma);
            s.insert(ma - mi);
        }
        cout << *s.begin() << endl;
    }
};
