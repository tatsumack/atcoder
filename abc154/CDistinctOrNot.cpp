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

class CDistinctOrNot {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        set<int> s;
        bool ok = true;
        REP(i, N) {
            int a;
            cin >> a;
            if (s.count(a)) ok = false;
            s.insert(a);
        }
        cout << (ok ? "YES" : "NO") << endl;

    }
};
