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

class DBaseN {
public:
    int M;

    int calc(int d, string& X) {
        int val = 0;
        for (auto c : X) {
            int n = c - '0';
            if (val > M / d) {
                return M + 1;
            }
            val *= d;
            val += n;
        }
        return val;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string X;
        cin >> X;
        cin >> M;
        if (X.size() == 1) {
            int val = X[0] - '0';
            cout << (val <= M ? 1 : 0) << endl;
            return;
        }
        int d = 0;
        for (auto c : X) {
            d = max(d, (int) (c - '0'));
        }
        int l = d + 1;
        if (calc(l, X) > M) {
            cout << 0 << endl;
            return;
        }
        int r = INF;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (calc(mid, X) <= M) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << (l - d) << endl;
    }
};
