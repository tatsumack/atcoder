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

class CSolutions {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        if ((N > 1 && M >= N - 1) || M < 0) {
            cout << -1 << endl;
            return;
        }
        cout << 1 << " " << 3 + 3 * (M + 1) << endl;
        REP(i, N - 1) {
            cout << 4 + 3 * i << " " << 5 + 3 * i << endl;
        }
    }
};
