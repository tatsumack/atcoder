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

class BTemplateMatching {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> A(N, vector<char>(N));
        vector<vector<char>> B(M, vector<char>(M));
        REP(i, N) REP(j, N) cin >> A[i][j];
        REP(i, M) REP(j, M) cin >> B[i][j];

        REP(x, N - M + 1) {
            REP(y, N - M + 1) {
                bool ok = true;
                REP(i, M) {
                    REP(j, M) {
                        if (A[x + i][y + j] != B[i][j]) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        cout << "No" << endl;
    }
};
