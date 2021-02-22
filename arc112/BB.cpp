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

class BB {
public:
    int calc1(int b, int c) {
        if (c <= 0) return 0;
        int to = b - c / 2;
        if (to <= 0) {
            return b * 2 + 1;
        }
        if (c & 1) {
            return (b - to + 1) * 2;
        } else {
            return (b - to) * 2 + 1;
        }
    }

    int calc2(int b, int c) {
        if (c <= 0) return 0;
        int to = b - c / 2;
        if (c & 1) {
            return (b - (to - 1)) * 2;
        } else {
            return (b - to) * 2 + 1;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int B, C;
        cin >> B >> C;
        int res = 0;
        if (B > 0) {
            res += calc1(B, C);
            res += calc2(-B - 1, C - 3);
        } else if (B == 0) {
            res++;
            res += calc2(-1, C - 2);
        } else {
            res += calc1(-B - 1, C - 3);
            res += calc2(B, C);
        }
        cout << res << endl;
    }
};
