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

class BXorOfSequences {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        REP(i, N) cin >> A[i];
        REP(i, M) cin >> B[i];
        vector<int> res;
        REP(i, N) {
            int a = A[i];
            bool ok = true;
            REP(j, M) {
                if (B[j] == a) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            res.push_back(a);
        }
        REP(i, M) {
            int b = B[i];
            bool ok = true;
            REP(j, N) {
                if (A[j] == b) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            res.push_back(b);
        }
        sort(res.begin(), res.end());
        REP(i, res.size()) cout << res[i] << " ";
        cout << endl;
    }
};
