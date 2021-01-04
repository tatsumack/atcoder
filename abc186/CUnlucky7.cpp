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

class CUnlucky7 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int res = 0;
        for (int n = 1; n <= N; n++) {
            bool ok = true;
            int tmp = n;
            while (tmp > 0) {
                int val = tmp % 10;
                if (val == 7) {
                    ok = false;
                    break;
                }
                tmp /= 10;
            }
            tmp = n;
            while (tmp > 0) {
                int val = tmp % 8;
                if (val == 7) {
                    ok = false;
                    break;
                }
                tmp /= 8;
            }
            if (ok) {
                res++;
            }
        }
        cout << res << endl;
    }
};
