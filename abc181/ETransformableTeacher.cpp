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

class ETransformableTeacher {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> H(N), W(M);
        REP(i, N) cin >> H[i];
        REP(i, M) cin >> W[i];
        sort(H.begin(), H.end());
        sort(W.begin(), W.end());
        vector<int> sumL(N), sumR(N);
        for (int i = 0; i + 1 < N; i += 2) {
            sumL[i + 1] = H[i + 1] - H[i];
            if (i - 1 >= 0) {
                sumL[i + 1] += sumL[i - 1];
            }
        }
        for (int i = N - 1; i - 1 >= 0; i -= 2) {
            sumR[i - 1] = H[i] - H[i - 1];
            if (i + 1 < N) {
                sumR[i - 1] += sumR[i + 1];
            }
        }
        int res = INF;
        REP(i, M) {
            int idx = upper_bound(H.begin(), H.end(), W[i]) - H.begin();
            int tmp = 0;
            if (idx % 2 == 0) {
                tmp += H[idx] - W[i];
                if (idx + 1 < N) {
                    tmp += sumR[idx + 1];
                }
                if (idx - 1 >= 0) {
                    tmp += sumL[idx - 1];
                }
            } else {
                tmp += W[i] - H[idx-1];
                if (idx < N) {
                    tmp += sumR[idx];
                }
                if (idx - 2 >= 0) {
                    tmp += sumL[idx - 2];
                }
            }
            res = min(res, tmp);
        }
        cout << res << endl;
    }
};
