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

class BLog {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int l = 1;
        int r = 1e10 + 7;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            int sum = mid * (mid + 1) / 2;
            if (sum <= N + 1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << N - l + 1 << endl;
    }
};
