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

class CDoubled {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int tmp = N;
        int num = 0;
        while (tmp > 0) {
            tmp /= 10;
            num++;
        }
        int res = 0;
        FOR(i, 1, 6) {
            if (2 * i > num) break;
            if (2 * i < num) {
                int tmp = 9;
                REP(j, i - 1) {
                    tmp *= 10;
                }
                res += tmp;
                continue;
            }
            int left = N;
            REP(j, i) {
                left /= 10;
            }
            FOR(j, 1, left) {
                int n = j;
                REP(k, i - 1) {
                    n /= 10;
                }
                if (n <= 0) continue;
                int tmp = j;
                REP(k, i) {
                    tmp *= 10;
                }
                tmp += j;
                if (tmp > N) continue;
                res++;
            }
        }
        cout << res << endl;
    }
};
