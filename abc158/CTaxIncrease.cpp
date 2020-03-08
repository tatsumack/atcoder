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

class CTaxIncrease {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B;
        cin >> A >> B;
        FOR(res, 1, 100000) {
            if (res * 8 / 100 == A && res * 10 / 100 == B) {
                cout << res << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
};
