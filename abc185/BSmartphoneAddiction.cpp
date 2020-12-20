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

class BSmartphoneAddiction {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, T;
        cin >> N >> M >> T;
        vector<int> a(M), b(M);
        REP(i, M) cin >> a[i] >> b[i];
        int cur = N;
        int t = 0;
        REP(i, M) {
            cur -= a[i] - t;
            if (cur <= 0) {
                cout << "No" << endl;
                return;
            }
            cur += b[i] - a[i];
            if (cur > N) cur = N;
            t = b[i];
        }
        cur -= T - t;
        cout << (cur <= 0 ? "No" : "Yes") << endl;
    }
};
