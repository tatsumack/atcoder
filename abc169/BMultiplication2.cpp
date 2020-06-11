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

class BMultiplication2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];
        int res = 1;
        REP(i, N) {
            if (A[i] == 0) {
                cout << 0 << endl;
                return;
            }
        }
        int sum = 0;
        bool ok = true;
        REP(i, N) {
            int n = A[i];
            while (n >= 10) {
                sum++;
                n /= 10;
            }
            if (n > 1) ok = false;
        }
        if (sum > 18 || (sum == 18 && !ok)) {
            cout << -1 << endl;
            return;
        }
        REP(i, N) {
            res *= A[i];
            if (res > 1000000000000000000) {
                cout << -1 << endl;
                return;
            }
        }
        cout << res << endl;
    }
};
