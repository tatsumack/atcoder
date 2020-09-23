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

class CAXBC {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int res = 0;
        FOR(a, 1, N) {
            int num = (N-1) / a;
            res += num;
        }
        cout << res << endl;
    }
};
