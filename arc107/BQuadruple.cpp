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

class BQuadruple {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        int res = 0;
        K = abs(K);
        for (int cd = 2; cd + K <= 2 * N; cd++) {
            int ab = K + cd;
            int lab = max(1LL, ab - N);
            if (lab > N) continue;
            int rab = min(N, ab - 1);
            int lcd = max(1LL, cd - N);
            if (lcd > N) continue;
            int rcd = min(N, cd - 1);
            res += (rab - lab + 1) * (rcd - lcd + 1);
        }
        cout << res << endl;
    }
};
