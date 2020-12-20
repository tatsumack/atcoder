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

class DStamp {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(M);
        REP(i, M) {
            cin >> A[i];
            A[i]--;
        }
        if (M == 0) {
            cout << 1 << endl;
            return;
        }
        if (N == M) {
            cout << 0 << endl;
            return;
        }
        sort(A.begin(), A.end());

        int len = INF;
        int cur = 0;
        REP(i, M) {
            if (A[i] - cur > 0) {
                len = min(len, A[i] - cur);
            }
            cur = A[i] + 1;
        }
        if (N - cur > 0) {
            len = min(len, N - cur);
        }

        int res = 0;
        cur = 0;
        REP(i, M) {
            res += (A[i] - cur) / len;
            if ((A[i] - cur) % len > 0) res++;
            cur = A[i] + 1;
        }
        res += (N - cur) / len;
        if ((N - cur) % len > 0) res++;
        cout << res << endl;
    }
};
