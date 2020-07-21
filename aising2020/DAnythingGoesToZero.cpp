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

class DAnythingGoesToZero {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        string X;
        cin >> N >> X;
        int num = 0;
        REP(i, N) {
            if (X[i] == '1') num++;
        }

        int n = N;
        int res = 0;
        while (n > 0) {
            int cur = 0;
            REP(i, N) {
                cur = cur << 1;
                if (X[i] == '1') {
                    cur |= 1;
                }
                if (cur > num) {
                    cur %= num;
                }
            }
            n = cur;
            int tmp = 0;
            REP(i, 60) {
                if (n >> i & 1) tmp++;
            }
            num = tmp;
            cout << num << endl;
            res++;
        }
        cout << res << endl;
    }
};
