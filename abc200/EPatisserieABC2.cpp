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

class EPatisserieABC2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        int cur = 0;
        int t;
        FOR(i, 3, 3 * N) {
            int num = (i - 1) * (i - 2) / 2;
            if (K <= cur + num) {
                t = i;
                K -= cur;
                break;
            }
            cur += num;
        }
        int a;
        cur = 0;
        FOR(i, 1, min(t - 2, N)) {
            if (t - i > N * 2) continue;
            int num = (t - i - 1);
            if (K <= cur + num) {
                a = i;
                K -= cur;
                break;
            }
            cur += num;
        }
        int b = K;
        int c = t - (a + b);
        cout << t << endl;
        cout << a << " " << b << " " << c << endl;
    }
};
