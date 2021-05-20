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

class A1192231 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        int two = 1;
        int res = INF;
        REP(b, 60) {
            if (two > N) break;
            int a = N / two;
            int c = N - a * two;
            res = min(res, a + b + c);
            two *= 2;
        }
        cout << res << endl;
    }
};
