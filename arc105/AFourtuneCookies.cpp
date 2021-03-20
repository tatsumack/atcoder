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

class AFourtuneCookies {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        vector<int> V(4);
        REP(i, 4) cin >> V[i];

        int sum = 0;
        REP(i, 4) sum += V[i];
        REP(i, 1 << 4) {
            int tmp = 0;
            REP(j, 4) {
                if (i >> j & 1) {
                    tmp += V[j];
                }
                if (sum == tmp * 2) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        cout << "No" << endl;
    }
};
