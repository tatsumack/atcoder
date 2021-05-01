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

class CMADTEAM {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<vector<int>> A(5, vector<int>(N));
        REP(i, N) {
            cin >> A[0][i] >> A[1][i] >> A[2][i] >> A[3][i] >> A[4][i];
        }

        vector<int> v(1 << 5);
        REP(k, N) {
            REP(i, 1 << 5) {
                int tmp = INF;
                REP(j, 5) {
                    if (i >> j & 1) {
                        tmp = min(tmp, A[j][k]);
                    }
                }
                v[i] = max(v[i], tmp);
            }
        }

        int res = 0;
        REP(i, N) {
            REP(j, N) {
                vector<int> tmp(5);
                REP(k, 5) {
                    tmp[k] = max(A[k][i], A[k][j]);
                }

                REP(k, 5) {
                    int s = 0;
                    REP(l, 5) {
                        if (k == l) continue;
                        if (tmp[l] < tmp[k]) {
                            s |= 1 << l;
                        }
                    }
                    if (v[s] >= tmp[k]) {
                        res = max(res, tmp[k]);
                    }
                }
            }
        }
        cout << res << endl;
    }
};
